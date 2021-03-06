/*
 *
 * Password Generator v1.0
 * By Agung Sudrajat Supriatna
 * 2020
 * Bandung
 * Indonesia
 */

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <time.h>

int findCharNum();
int main(int argc, string argv[])
{
	if (argc != 3) {
		printf("Strong Password Generator ver 1.2 by Agung Sudrajat Supriatna\n\n");
		printf("Usage: password<space>number of password<space>password length\n");
		
		exit(1);
	}


	int nPass = 0;
	int passLength = 0;
	char huruf[72] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~!@#$%^&*()-+{}:<>?";
	char angka[11] = "0123456789";
	
	char *hurufPtr;
	char *angkaPtr;

	hurufPtr = huruf;
	angkaPtr = angka;
	
	//what is this?
	srand(time(0));

	if (argc == 3) {
		//convert from string to integer
		nPass = atoi(argv[1]);
		passLength = atoi(argv[2]);	
	}

	//generate password:
	for(int i = 0; i < nPass; i++) {
		printf("Password number %d: \n", i + 1);

		for(int j = 0; j < passLength-2; j++) {
			printf("%c", huruf[findCharNum(71)]);	
		}

		for(int j = 0; j < 2; j++) {
			printf("%c", angka[findCharNum(10)]);
		}
		printf("\n\n");
	}

	printf("\n\n\nSave this(these) in your secret notes.\n");
	printf("Regularly change your password is a good habit.\n");
	printf("The code is available on github.\n");

	return 0;
}


int findCharNum(int digit)
{
	int index = 0;

	index = rand() % digit;
	//printf("Index : %d",index);
	return index;
}
