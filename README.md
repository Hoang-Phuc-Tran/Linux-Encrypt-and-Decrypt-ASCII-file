![Capture1111](https://github.com/Hoang-Phuc-Tran/Ubuntu-Encrypt-and-Decrypt-ASCII-file/assets/120700092/94e4e5bc-12ec-445c-b954-879256c56150)


# cryptoMagic Utility

The `cryptoMagic` utility, developed in C, provides a secure solution for encrypting and decrypting ASCII files on Linux. It ensures that the contents of files remain unreadable until decrypted using this versatile tool.

## Project Highlights

- Reinforce C programming techniques, including file input/output with ASCII files and command-line argument processing.
- Emphasize Linux software development best practices by establishing a well-organized directory structure and crafting a makefile.

## Command-Line Usage

The `cryptoMagic` utility supports two command-line switches: `--encrypt` and `--decrypt`. If no switch is specified, `--encrypt` is assumed. Users supply the utility with the name of the ASCII input file to be encrypted or decrypted as an argument.

Examples:

1. Encrypting:
   - Running `cryptoMagic --encrypt myFile.txt` encrypts the contents of `myFile.txt` into an encrypted file named `myFile.crp`.
   - Running `cryptoMagic myFile.txt` also encrypts `myFile.txt` into `myFile.crp`.

2. Decrypting:
   - Running `cryptoMagic --decrypt myFile.crp` decrypts the contents of `myFile.crp` into a decrypted file named `myFile.txt`.

The utility seamlessly converts input filenames to their encrypted or decrypted counterparts while maintaining the base filename. For encryption, the file extension becomes `.crp`, and for decryption, it becomes `.txt`.

## Project Benefits

By engaging in the `cryptoMagic` project, you will:

- Strengthen your C programming skills.
- Gain hands-on experience in secure file encryption and decryption.
- Practice proper Linux software project development, including directory structuring and makefile creation.

Explore the world of secure file manipulation and enhance your understanding of C programming and Linux software development with the `cryptoMagic` utility.

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
