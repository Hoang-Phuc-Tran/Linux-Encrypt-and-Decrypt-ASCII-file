#  
#  FILE          : makefile
#  PROJECT       : A-01 - The cryptoMagic Utility
#  By	         : Hoang Phuc Tran
#  FIRST VERSION : Hoang Phuc Tran
#  DESCRIPTION   : This make file will compile the source files
#
./bin/cryptoMagic : ./obj/cryptoMagic.o ./obj/encryptDecrypt.o
	cc ./obj/cryptoMagic.o ./obj/encryptDecrypt.o -o ./bin/cryptoMagic
#
# =======================================================
#                     Dependencies
# =======================================================                     
./obj/cryptoMagic.o : ./src/cryptoMagic.c ./inc/cryptoMagic.h
	cc -c ./src/cryptoMagic.c -o ./obj/cryptoMagic.o

./obj/encryptDecrypt.o : ./src/encryptDecrypt.c ./inc/cryptoMagic.h
	cc -c ./src/encryptDecrypt.c -o ./obj/encryptDecrypt.o

#
# =======================================================
# Other targets
# =======================================================  

all : ./bin/cryptoMagic                   

clean:
	rm -f ./bin/*
	rm -f ./obj/*.o
	


