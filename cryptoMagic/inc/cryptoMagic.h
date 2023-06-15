/*
 * Project:	A-01 - The cryptoMagic Utility
 * By:	    	Hoang Phuc Tran
 * Student ID:  8789102
 * Date:	January 19, 2023
 * Description: This file contains prototypes
 */
#pragma once

#define MAGICNUMBER 50
#define MAX_CHARACTER 255
#define MAX_HEXIMAL 3

// prototypes
int extensionFile(char* extensionFile, char* noneExtensionFile, int mode);
int encryption(char* originalFile, char* encryptedFile);
int decryption(char* originalFile, char* decryptedFile);
int heximalToDecimal(char input);
