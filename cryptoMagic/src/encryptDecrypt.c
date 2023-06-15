/*
 * Project:	A-01 - The cryptoMagic Utility
 * By:	    	Hoang Phuc Tran
 * Student ID:  8789102
 * Date:	January 19, 2023
 * Description: This file contains the definition of functions in the cryptoMagic.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/cryptoMagic.h"

#pragma warning(disable: 4996)

 /*
 * Function: extensionFile()
 * Description:  This function will get rid of the extension of the orginal File and add the ".txt" or ".crp" extension which will depend on the mode.
 * Parameters: char* extensionFile - char* noneExtensionFile - int mode
 * Returns: 0 indicates successfull, otherwise fail.
 */
int extensionFile(char* extensionFile, char* noneExtensionFile, int mode)
{
	size_t length = 0;
	size_t lengthOfExtension = 0;
	size_t stringFinal = 0;
	char* tmpFile = NULL;


	// Calculate the length of orginalFile
	length = strlen(extensionFile);

	tmpFile = strrchr(extensionFile, '.');

	// Take the length of the string
	lengthOfExtension = strlen(tmpFile);

	// Calculate the length to find location of the string name of the primary team
	stringFinal = length - lengthOfExtension;

	//Copy the name to the string called nameOfPrimary
	strncpy(noneExtensionFile, extensionFile, stringFinal);
	noneExtensionFile[MAGICNUMBER - 1] = 0;

	if (mode == 1)
	{
		strcat(noneExtensionFile, ".crp");
		return 0;
	}
	else
	{
		strcat(noneExtensionFile, ".txt");
		return -1;
	}

	return 0;
}

/*
 * Function: encryption()
 * Description:  This function will encrypt the original file then out put it in the new file.
 * Parameters: char* originalFile - char* encryptedFile 
 * Returns: 0 indicates successfull, otherwise fail.
 */
int encryption(char* originalFile, char* encryptedFile)
{
	FILE* File1;
	FILE* File2;

	int ch = 0;
	int outchar = 0;

	// Get input from the original File
	File1 = fopen(originalFile, "r");

	// Open file to write
	File2 = fopen(encryptedFile, "w");


	if (File1 == NULL)
	{
		printf("ERROR: Can't open file to read!\n");
		return -1;
	}
	else if (File2 == NULL)
	{
		printf("ERROR: Can't open file to write!\n");
		return -1;
	}
	else
	{
		ch = fgetc(File1);

		while (ch != EOF)
		{
			// Check if a character is a 'tab' character
			if (ch == 9)
			{
				fputc('T', File2);
				fputc('T', File2);
			}
			// Chec if a character is a newline or carriage return character
			else if ((ch == 10) || (ch == 13))
			{
				// write a character to file
				fputc(ch, File2);
			}
			else
			{
				outchar = ch - 16;

				// Check if outchar is less than 32
				if (outchar < 32)
				{
					outchar = (outchar - 32) + 144;
				}

				// Write 2 heximal number to the file 
				fprintf(File2, "%X", outchar);
			}

			ch = fgetc(File1);
		}


		// Check errors 
		if (ferror(File1))
		{
			printf("Error reading line from file");
			// If any errors occur, close the file
			if (fclose(File1) != 0)
			{
				printf("Error closing the file\n");
				return -1;
			}
		}


		// Check errors 
		if (ferror(File2))
		{
			printf("Error reading line from file");
			// If any errors occur, close the file
			if (fclose(File2) != 0)
			{
				printf("Error closing the file\n");
				return -1;
			}
		}
	}
	return 0;
}

/*
 * Function: decryption()
 * Description:  This function will decrypt the original file then out put it in the new file.
 * Parameters: char* originalFile - char* encryptedFile
 * Returns: 0 indicates successfull, otherwise fail.
 */
int decryption(char* originalFile, char* encryptedFile)
{
	// Initialize a FILE pointer
	FILE* File1;
	FILE* File2;

	char heximalNumber[3] = { 0 };
	int ch = 0;
	int outchar = 0;
	int counter = 0;

	// Get input from the original File
	File1 = fopen(originalFile, "r");

	// Open file to write
	File2 = fopen(encryptedFile, "w");


	if (File1 == NULL)
	{
		printf("ERROR: Can't open file to read!\n");
		return -1;
	}
	else if (File2 == NULL)
	{
		printf("ERROR: Can't open file to write!\n");
		return -1;
	}
	else
	{
		ch = fgetc(File1);

		while (ch != EOF)
		{
			// Check if a character is a 'tab' character
			if ((ch == 10) || (ch == 13))
			{
				// write a character to file
				fputc(ch, File2);
			}
			// User counter variable to put a character to string
			else if (counter == 0)
			{
				heximalNumber[0] = ch;

				counter++;
			}
			// Check to put another character to string
			else if (counter != 0)
			{
				heximalNumber[1] = ch;

				// reset counter
				counter = 0;

				// Check if it's a tab character
				if (heximalNumber[0] == 'T' && heximalNumber[1] == 'T')
				{
					ch = 9;
					// write a character to file
					fputc(ch, File2);
				}
				// If it's not, we decrypt it
				else
				{
					outchar = (heximalToDecimal(heximalNumber[0]) * 16);
					outchar = outchar + (heximalToDecimal(heximalNumber[1]));

					outchar = outchar + 16;

					if (outchar > 127)
					{
						outchar = (outchar - 144) + 32;
					}

					// write a character to file
					fputc(outchar, File2);
				}
			}
			
			ch = fgetc(File1);
		}


		// Check errors 
		if (ferror(File1))
		{
			printf("Error reading line from file");
			// If any errors occur, close the file
			if (fclose(File1) != 0)
			{
				printf("Error closing the file\n");
				return -1;
			}
		}


		// Check errors 
		if (ferror(File2))
		{
			printf("Error reading line from file");
			// If any errors occur, close the file
			if (fclose(File2) != 0)
			{
				printf("Error closing the file\n");
				return -1;
			}
		}
	}
	return 0;
	
}

/*
 * Function: heximalToDecimal()
 * Description:  This function will convert a heximal number to a decimal number
 * Parameters: char inputChar
 * Returns: a decimal number
 */
int heximalToDecimal(char inputChar)
{
	if (inputChar >= '0' && inputChar <= '9')
	{
		return inputChar - 48;
	}
	else if (inputChar == 'A')
	{
		return 10;
	}
	else if (inputChar == 'B')
	{
		return 11;
	}
	else if (inputChar == 'C')
	{
		return 12;
	}
	else if (inputChar == 'D')
	{
		return 13;
	}
	else if (inputChar == 'E')
	{
		return 14;
	}
	else if (inputChar == 'F')
	{
		return 15;
	}
	else
	{
		return -1;
	}
}

