//Author: Belle Lodovico
//Date: 5/01/26
//Purpose: Programming Project 10


#include <stdio.h>
#include <stdbool.h>
#define FILEIN "mystery.txt"
#define CAP 5
#define ROW 6
#define COL 5


void getWord(char str[]);
void getGuess(int guess, int final, int row, int col, char str[][col]);
int guessLength(int row, int col, arrstr[][col]);
void convertLowercase(int row, int col, char str[][col]);
void checkLetterRightSpace(bool *value0, bool *value1, bool *value2, bool *value3, bool *value4, char arr[], const char str[], int row, int col, char arrstr[][col]);
void checkLetterWrongSpace(bool lett0, bool lett1, bool lett2, bool lett3, bool lett4, char arr[], const char str[], int row, int col, char arrstr[][col]);
void displayLine();
void displayGuess(int row, int col, char str[][col]);
void displayPoint(int size, char arr[]);
void checkCorrect(const char str[], int row, int col, char arrstr[][col]);


int main(){
	char pointArr[CAP], wrdStr[CAP], guessStr[ROW][COL];
	bool letter0, letter1, letter2, letter3, letter4;
	int count = 1, i = 0;
	
	getWord(wrdStr);
	
	do{
		getGuess(count, i, ROW, COL, guessStr);
		convertLowercase(count, ROW, COL, guessStr);
		checkCorrect(wrdStr, count, COL, guessStr);
		checkLetterRightSpace(&letter0, &letter1, &letter2, &letter3, &letter4, pointArr, wrdStr, count, COL, guessStr);
		checkLetterWrongSpace(letter0, letter1, letter2, letter3, letter4, pointArr, wrdStr, count, COL, guessStr);
		displayLine();
		displayGuess(count, COL, guessStr);
		displayPoint(CAP, pointArr);
		count++;
	}while();
		
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

void getGuess(int guess, int row, int final, int col, char str[][col]){//need to check it's 5 letters long and final message
	printf("GUESS %d! Enter your guess: ", guess);
	scanf("%s", str[i]);
		while((str[i] < '5') || (str[i] > '5')){
			printf("Your guess must be 5 letters long\nPlease try again: ");
			scanf("%s", str[i]);
		}
	while(guess == final){
		printf("FINAL GUESS: ");
		scanf("%s", str[final]);
			while((str[i] < '5') || (str[i] > '5')){
			printf("Your guess must be 5 letters long\nPlease try again: ");
			scanf("%s", str[i]);
			}
	}
	
	

	
}

int guessLength(int row, int col, arrstr[][col]){
	for(int i = 0; str[i] != '\0'; i++);	
	return i; 
}

void convertLowercase(int row, int col, char str[][col]){
	for(int cI = 0; cI < col; cI++){
		if(str[row][cI] >= 'A' && str[row][cI] <= 'Z'){
			str[row][cI] = str[row][cI] - ('A' - 'a');
		}
	}
}

void checkLetterRightSpace(bool *value0, bool *value1, bool *value2, bool *value3, bool *value4, char arr[], const char str[], int row, int col, char arrstr[][col]){
	int let0, let1, let2, let3, let4;	
	if(str[0] == arrstr[row][0]){
		arrstr[row][0] = arrstr[row][0] - ('a' - 'A');
		arr[0] = ' ';
		let0 = 1; 
	}
	else{
		let0 = 0;
	}
	if(str[1] == arrstr[row][1]){
		arrstr[row][1] = arrstr[row][1] - ('a' - 'A');
		arr[1] = ' ';
		let1 = 1; 
	}
	else{
		let1 = 0;
	}
	if(str[2] == arrstr[row][2]){
		arrstr[row][2] = arrstr[row][2] - ('a' - 'A');
		arr[2] = ' ';
		let2 = 1; 
	}
	else{
		let2 = 0;
	}
	if(str[3] == arrstr[row][3]){
		arrstr[row][3] = arrstr[row][3] - ('a' - 'A');
		arr[3] = ' ';
		let3 = 1; 
	}
	else{
		let3 = 0;
	}
	if(str[4] == arrstr[row][4]){
		arrstr[row][4] = arrstr[row][4] - ('a' - 'A');
		arr[4] = ' ';
		let4 = 1; 
	}
	else{
		let4 = 0;
	}
	
	*value0 = let0 == true;
	*value1 = let1 == true;
	*value2 = let2 == true;
	*value3 = let3 == true;
	*value4 = let4 == true;
}	

void checkLetterWrongSpace(bool lett0, bool lett1, bool lett2, bool lett3, bool lett4, char arr[], const char str[], int row, int col, char arrstr[][col]){
	if(!lett0){
		for(int i = 1; i < col; i++){	
			if(str[0] == arrstr[row][i]){
				arr[i] = '^';
			}
			else{
				arr[i] = ' ';
			}
		}
	}
	if(!lett1){
		if(str[1] == arrstr[row][0]){
			arr[0] = '^';
		}
		else{
			arr[0] = ' ';
		}
		for(int i = 2; i < col; i++){
			if(str[1] == arrstr[row][i]){
				arr[i] = '^';
			}
			else{
				arr[i] = ' ';
			}
		}
	}
	if(!lett2){
		for(int i = 0; i < col - 3; i++){
			if(str[2] == arrstr[row][i]){
				arr[i] = '^';
			}
			else{
				arr[i] = ' ';	
			}
		}
		for(int i = 3; i < col; i++){
			if(str[2] == arrstr[row][i]){
				arr[i] = '^';
			}
			else{
				arr[i] = ' ';
			}
		}
	}
	if(!lett3){
		for(int i = 0; i < col - 2; i++){
			if(str[3] == arrstr[row][i]){
				arr[i] = '^';
			}
			else{
				arr[i] = ' ';
			}
		}
		if(str[3] == arrstr[row][4]){
			arr[4] = '^';
		}
		else{
			arr[4] = ' ';
		}
	}
	if(!lett4){
		for(int i = 0; i < col - 1; i++){
			if(str[4] == arrstr[row][i]){
				arr[i] = '^';
			}
			else{
				arr[i] = ' ';
			}
		}
	}
}

void displayLine(){
	printf("================================\n");
}

void displayGuess(int row, int col, char str[][col]){
	for(int rI = 0; rI < row + 1; rI++){
		printf("%s\n", str[row]);
	}
}

void displayPoint(int size, char arr[]){
	for(int i = 0; i < size; i++){
		printf("%c", arr[i]);
	}
	printf("\n");
}

void checkCorrect(const char str[], int row, int col, char arrstr[][col]){
	int check = 0;
	for(int i = 0; i < col; i++){
		if(str[i] == arrstr[row][i]){
			check = 1;	
		}
	}
	if(((row + 1) == '1') && (check = '1')){
		printf("You won in %d guesses!\nGOATED!\n", row + 1);
		printf("\n");
	}
	else if((((row + 1) == '2') || ((row + 1) == '3')) && ((check == '1'))){
		printf("You won in %d guesses!\nAmazing!\n", row + 1);
		printf("\n");
	}
	else if((((row + 1) == '4') || ((row + 1) == '5')) && ((check == '1'))){
		printf("You won in %d guesses!\nNice!\n", row + 1);
		printf("\n");
	}
	else if((row + 1) == '6'){
		printf("You won in %d guesses!", row + 1);
		printf("\n");
	}
	else{
	
	}

}
