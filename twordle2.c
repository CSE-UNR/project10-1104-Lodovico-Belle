//Author: Belle Lodovico
//Date: 5/01/26
//Purpose: Programming Project 10

#include <stdio.h>
#include <stdbool.h>
#define FILEIN "mystery.txt"
#define WRDLEN 5
#define MAXATT 6
#define SIZE 50

void getWord(char str[]);
void getGuess(int attmptnum, char str[]);
int findLength(const char str[]);
bool checkGuessValid(int strleng, int leng, const char str[]);
void convertLowercase(int leng, char str[]);
void storeGuesses(int attmptnum, int leng, const char str[], int col, char arrstr[][col]);
void checkGuess(bool used[], int attmptnum, int leng, int col, char arr[][col], const char str[], char arrstr[][col]);
void guessInvalid(bool value, char str[]);
void display(int attmptnum, int leng, int col, char arr[][col], char arrstr[][col]);
//void displayPoint(int leng, char arr[]);
bool guessCorrect(int attmptnum, int leng, const char str[], int col, char arrstr[][col]);
void displayLine();

int main(){
	char wrdStr[WRDLEN + 1], guessStr[SIZE], guessesStr[MAXATT][WRDLEN + 1], pntArr[MAXATT][WRDLEN + 1];
	int attempt = 0, strlen; 
	bool checkvalid, checkcorrect, usedArr[WRDLEN] = {false};
	
	getWord(wrdStr);
	
	while(attempt < WRDLEN){	
		getGuess(attempt, guessStr);
		displayLine();
		strlen = findLength(guessStr);
		convertLowercase(WRDLEN, guessStr);
		checkvalid = checkGuessValid(strlen, WRDLEN, guessStr);
			if(!checkvalid){
				guessInvalid(checkvalid, guessStr);
			}
		storeGuesses(attempt, WRDLEN, guessStr, WRDLEN + 1, guessesStr);
		checkGuess(usedArr, attempt, WRDLEN, WRDLEN + 1, pntArr, wrdStr, guessesStr);
//		displayPoint(attempt, pntArr);
		checkcorrect = guessCorrect(attempt, WRDLEN, wrdStr, WRDLEN + 1, guessesStr);
		attempt++;
		
		display(attempt, WRDLEN, WRDLEN + 1, pntArr, guessesStr);
		if(checkcorrect){
			if(attempt == '1'){
				printf("         You won in %d guesses!\n", attempt);
				printf("         GOATED!\n");
				return 0;
			}
			if(attempt == '2' || attempt == '3'){
				printf("         You won in %d guesses!\n", attempt);
				printf("         Amazing!\n");
				return 0;
			}
			if(attempt == '4' || attempt == '5'){
				printf("         You won in %d guesses!\n", attempt);
				printf("         Nice!\n");
				return 0;
			}
			if(attempt == '6'){
				printf("         You won in %d guesses!\n", attempt);
				return 0;
			}	
		}
	}
	
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

void getGuess(int attmptnum, char str[]){
	printf("GUESS %d! Enter your guess: ", attmptnum + 1);
	scanf("%s", str);
}

int findLength(const char str[]){
	int len;
	for(len = 0; str[len] != '\0'; len++);
	return len;
}

bool checkGuessValid(int strleng, int leng, const char str[]){
	if(strleng != leng){
		return false;
	}
	for(int i = 0; i < leng; i++){
		if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))){
			return false;
		}
	}
	return true;
}

void guessInvalid(bool value, char str[]){
	if(!value){
		printf("Your guess must be 5 letters long.\n");
		printf("Please try again: ");
		scanf("%s", str);
	}
}

void convertLowercase(int leng, char str[]){
	for(int i = 0; i < leng; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] - ('A' - 'a');
		}
	}
}

void storeGuesses(int attmptnum, int leng, const char str[], int col, char arrstr[][col]){
	for(int i = 0; i < leng; i++){
		arrstr[attmptnum][i] = str[i];
	}
	arrstr[attmptnum][leng] = '\0';
}

void checkGuess(bool used[], int attmptnum, int leng, char arr[][col], const char str[], int col, char arrstr[][col]){
	for(int i = 0; i < leng; i++){
		if(arrstr[attmptnum][i] == str[i]){
			arrstr[attmptnum][i] = arrstr[attmptnum][i] - ('a' - 'A');
			arr[attmptnum][i] = ' ';
			used[i] = true;
		}
		else{
			arr[attmptnum][i] = ' ';
		}
	}
		
	for(int i = 0; i < leng; i++){
		if(arrstr[attmptnum][i] >= 'A' && arrstr[attmptnum][i] <= 'Z')continue;
			
		for(int j = 0; j < leng; j++){
			if(!used[j] && arrstr[attmptnum][i] == str[j]){
				arr[attmptnum][i] = '^';
				used[j] = true;
				break;
			}
		}
	}
	arr[leng] = '\0';
}

void display(int attmptnum, int leng, char arr[], int col, char arrstr[][col]){	
	printf("%s\n", arrstr[attmptnum]);
	for(int j = 0; arr[j] != '\0'; j++){
		printf("%s", arr[j]);
	}
}

//void displayPoint(int leng, char arr[]){
//	for(int i = 0; i < leng; i++){
//		printf("%c\n", arr[i]);
//	}
//}

bool guessCorrect(int attmptnum, int leng, const char str[], int col, char arrstr[][col]){
	for(int i = 0; i < leng; i++){
		if(str[i] != arrstr[attmptnum][i]){
			return false; 
		}
	}
	return true;
}

void displayLine(){
	printf("================================\n");
}
