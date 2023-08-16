![Capture1111](https://github.com/Hoang-Phuc-Tran/Ubuntu-Encrypt-and-Decrypt-ASCII-file/assets/120700092/94e4e5bc-12ec-445c-b954-879256c56150)

Description: This utility, developed in C, allows encryption and decryption of ASCII files, ensuring their contents remain unreadable until decrypted using the utility.<br/><br/>
The project emphasizes Linux software development practices, including establishing the required directory structure and crafting a makefile. It also reinforces essential C programming techniques, such as working with file input/output using ASCII files and processing command-line arguments.<br/><br/>
The "cryptoMagic" utility offers two command-line switches: "--encrypt" and "--decrypt." If no switch is specified, "--encrypt" is assumed. Users provide the utility with the name of the ASCII input file to be encrypted or decrypted as an argument. For instance:<br/>
- Running "cryptoMagic --encrypt myFile.txt" encrypts the contents of "myFile.txt" into an encrypted file named "myFile.crp."<br/>
- Running "cryptoMagic myFile.txt" also encrypts the contents of "myFile.txt" into "myFile.crp."<br/>
- Running "cryptoMagic --decrypt myFile.crp" decrypts the contents of "myFile.crp" into a decrypted file named "myFile.txt."<br/><br/>

The utility seamlessly transforms input filenames into their corresponding encrypted or decrypted forms, maintaining the original base filename while updating the file extension to ".crp" for encryption and ".txt" for decryption. This project serves as a practical exercise in building a secure file encryption/decryption tool with a focus on C programming techniques and proper Linux software project development practices.
