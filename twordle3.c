//Author: Belle Lodovico
//Date: 5/01/26
//Purpose: Programming Project 10

#include <stdio.h>
#include <stdbool.h>
#define FILEIN "mystery.txt"
#define WLENG 5
#define ATTEMPTS 6


void getWord(char str[]);
int findStringLen(int col, char row[]);
void convertLowercase(int len, char str[], int col, char row[]); 
void getGuess(int attempts, int count, int col, char row[]);
void guessInvalid(int col, char row[]);
void checkGuess(int len, char arr[], const char str[], int col, char row[]);
void displayGuess(int len, int col, char row[]);
void displayArr(int len, char arr[]);
void displayLine();
void checkSame(int len, const char str[], int col, char row[]);


int main(){
	char wrdStr[WLENG + 1], guessStr[ATTEMPTS][WLENG + 1], ptArr[WLENG + 1];
	int attempt = 0, strlen; 
	

	getWord(wrdStr);
	getGuess(ATTEMPTS, attempt + 1, WLENG + 1, guessStr[attempt]);
	checkSame(WLENG, wrdStr, WLENG + 1, guessStr[attempt]);
	strlen = findStringLen(WLENG + 1, guessStr[attempt]);
	while(strlen != WLENG){
		guessInvalid(WLENG + 1, guessStr[attempt]);
		strlen = findStringLen(WLENG + 1, guessStr[attempt]);
	}
	displayLine();
	checkGuess(WLENG, ptArr, wrdStr, WLENG + 1, guessStr[attempt]);
	displayGuess(WLENG, WLENG + 1, guessStr[attempt]);
	displayArr(WLENG, ptArr);

	

	return 0;
}

void getWord(char str[]){
	FILE* fPtr; 
	fPtr = fopen(FILEIN, "r");
	if(fPtr == NULL){
		printf("Could not open file\n");
	}
	fscanf(fPtr, "%s", str);
	fclose(fPtr);
}

int findStringLen(int col, char row[]){
	int len;
	for(len = 0; row[len] != '\0'; len++);
	return len;
}

void convertLowercase(int len, char str[], int col, char row[]){
	for(int i = 0; i < len; i++){
		if(row[i] >= 'A' && row[i] <= 'Z'){
			row[i] = row[i] - ('A' - 'a');
		}
	}
}

void getGuess(int attempts, int count, int col, char row[]){
	if(count < attempts){
		printf("GUESS %d! Enter your guess: ", count);
		scanf("%s", row);
	}
	else{
		printf("FINAL GUESS: ");
		scanf("%s", row);
	}	
}

void guessInvalid(int col, char row[]){
	printf("Your guess must be 5 letters long.\n");
	printf("Please try again: ");
	scanf("%s", row);
}

void checkGuess(int len, char arr[], const char str[], int col, char row[]){
	for(int i = 0; i < len; i++){
		if(row[i] == str[i]){
			row[i] = row[i] - ('a' - 'A');
			arr[i] = ' ';
		}
		else{
			arr[i] = ' ';
		}
	}
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
			if((!(row[i] >= 'A' && row[i] <= 'Z')) && (row[i] == str[j])){
				arr[i] = '^';
			}
		}
	}
}

void displayGuess(int len, int col, char row[]){
	printf("%s\n", row);
}

void displayArr(int len, char arr[]){
	for(int i = 0; i < len; i++){
		printf("%c", arr[i]);
	}
	printf("\n");
}

void displayLine(){
	printf("================================\n");
}

void checkSame(int len, const char str[], int col, char row[]){
	for(int i = 0; i < len; i++){
		if(row[i] == str[i]){
			
		}
	}
}


