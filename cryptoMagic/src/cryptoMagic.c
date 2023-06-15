/*
 * Project:	A-01 - The cryptoMagic Utility
 * By:	    	Hoang Phuc Tran
 * Student ID:  8789102
 * Date:	January 19, 2023
 * Description:This application is used writing an encrypting / decrypting utility for Linux in the C programming language. 
		This utility will take any ASCII file and encrypt it in such a way that its contents are not readable
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/cryptoMagic.h"

#pragma warning(disable: 4996)


int main(int argc, char* argv[])
{
	// Initialize a FILE pointer
	FILE* fp = NULL;
	char orginalFile[MAGICNUMBER] = { 0 };			// Original file is used to encrypt or decrypt
	char modifiedFile[MAGICNUMBER] = { 0 };			// contains the path of encrypted or decrypted file
	char ch = '\0';
	int i = 0;

	if (argc == 3)
	{
		// Check if the switches are correct
		if (strcmp(argv[1], "-encrypt") == 0 || strcmp(argv[1], "-decrypt") == 0)
		{	
			strcpy(orginalFile, argv[2]);

			// Get rid of .txt 
			if (strchr(orginalFile, '.') == NULL)
			{
				// Check if filename does not contain '.'
				strcpy(modifiedFile, orginalFile);
			}
			else
			{
				// Check if the switch is "-encrypt"
				if (strcmp(argv[1], "-encrypt") == 0)
				{
					// Get rid of extension
					extensionFile(orginalFile, modifiedFile, 1);

					// Encrypts file
					encryption(orginalFile, modifiedFile);
				}
				// Check if the switch is "-decrypt"
				if (strcmp(argv[1], "-decrypt") == 0)
				{
					// Get rid of extension
					extensionFile(orginalFile, modifiedFile, 2);

					// Decrypts file
					decryption(orginalFile, modifiedFile);
				}
			}
		}
		else
		{
			// Display the error message.
			printf("Error: Incorrect Switch.\n");
		}

	}
	// Check if the default switch
	else if (argc == 2)
	{
		strcpy(orginalFile, argv[1]);

		// Get rid of .txt 
		if (strchr(orginalFile, '.') == NULL)
		{
			// Check if filename does not contain '.'
			strcpy(modifiedFile, orginalFile);
		}
		else
		{
			// Get rid of extension
			extensionFile(orginalFile, modifiedFile, 1);

			// Encrypts file
			encryption(orginalFile, modifiedFile);
		}
	}
	else
	{
		// Display the error message.
		printf("Error: Incorrect number of arguments.\n");
	}
	

	return 0;
}




