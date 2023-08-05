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
int main(int argc, char *argv[])
{
  // argc counts from 1.
  // argv counts from 0.
	if (argc != 4) {
		printf("Strong Password Generator ver 1.4 by Agung Sudrajat Supriatna\n\n");
		printf("Usage: password<space>number of password<space>password length<space>notes\n");
		
		exit(1);
	}

  // save output file
  FILE *fptr;

  // open the file
  fptr = fopen("pass_bank.txt","a");

  if (fptr == NULL)
  {
    printf("Error!");
    exit(1);
  }


	int nPass = 0;
	int passLength = 0;
  string notes;
  //char *notes;

	// char huruf[72] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~!@#$%^&*()-+{}:<>?";
	char hurufBesar[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char hurufKecil[27] = "abcdefghijklmnopqrstuvwxyz";
	char angka[11] = "0123456789";
	char symbol[20] = "~!@#$%^&*()-+{}:<>?";
	
  //char *angkaPtr;
  //char *hurufPtr;
  char *hurufBesarPtr;
  char *hurufKecilPtr;
  char *angkaPtr;
  char *symbolPtr;
  
  

	//hurufPtr = huruf;
	//angkaPtr = angka;
	
	hurufBesarPtr = hurufBesar;
	hurufKecilPtr = hurufKecil;
	angkaPtr = angka;
	symbolPtr = symbol;
	
	//what is this?
	srand(time(0));

	if (argc == 4) {
		//convert from string to integer
		nPass = atoi(argv[1]);
		passLength = atoi(argv[2]);
    notes = argv[3];  
	}


  //printf("%s ", notes);
  fprintf(fptr,"%s  ", notes);
	//generate password:
	for(int i = 0; i < nPass; i++) {
		//printf("Password number %d: \n", i + 1);
		// fprintf(fptr,"Password number %d: \n", i + 1);

		for(int j = 0; j < passLength-3; j++) {
			//printf("%c", huruf[findCharNum(71)]);	
      fprintf(fptr,"%c",hurufBesar[findCharNum(26)]);
		}

		for(int j = 0; j < 1; j++) {
			fprintf(fptr, "%c",hurufKecil[findCharNum(26)]);
		}

		for(int j = 0; j < 1; j++) {
			fprintf(fptr, "%c",angka[findCharNum(10)]);
		}

		for(int j = 0; j < 1; j++) {
			fprintf(fptr, "%c",symbol[findCharNum(19)]);
		}

		//printf("\n\n");
    fprintf(fptr,"\n");
	}

	printf("The password is saved in pass_bank.txt file.\n");
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
