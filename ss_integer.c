// This program displays an integer in seven-segment display format.
// Author: Bazillah Zargar

#include <stdio.h>
#include <stdlib.h>

// Main method
// Input: none
// Effect: Prompts user to enter an integer and converts it to a seven-segment display format.
// Output: Prints the integer in seven-segment diaplay format.
int main(void){
    const char segments[10][3][3] = {
        // 0 representation
        {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
        // 1 representation
        {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
        // 2 representation
        {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
        // 3 representation
        {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
        // 4 representation
        {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
        // 5 representation
        {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
        // 6 representation
        {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
        // 7 representation
        {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
        // 8 representation
        {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
        // 9 representation
        {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}},
    };

    char cont = 'Y';
    while (cont == 'Y' || cont == 'y') {
        
        int userInput;
        printf("Enter the integer you wish to see in seven-segment display format: ");
        scanf(" %d", &userInput);

        int sign = 0;
        // Determine the sign of the integer
        if (userInput < 0){
            sign = -1;
            userInput = userInput * -1;
        }
        else if (userInput > 0) {
            sign = 1;
        }
        
        // If the user input is 0 then print 0
        if (userInput == 0){
            for (int a = 0; a < 3; a++){
                for (int b = 0; b < 3; b++){
                    printf("%c", segments[0][a][b]);
                }
                printf("\n");

            }
        }
        // If the user input is not 0, then separate the integer into digits and store them in reverse order in an array. 
        else {
            int digitLen = 0;
            int digits[100];

            while (userInput != 0) {
                digits[digitLen] = userInput % 10;
                userInput = userInput / 10;
                digitLen++;
            }
            
            // Print the sign of the integer followed by each digit of the integer   
            for (int a = 0; a < 3; a++){
                if (sign == -1){
                    if (a == 1){
                        printf("_");
                    }
                    else{
                        printf(" ");
                    }
                }
                for (int i = (digitLen-1); i >= 0; i--){
                    for (int b = 0; b < 3; b++){
                        printf("%c", segments[digits[i]][a][b]);
                    }
                }
                printf("\n");
            }
        }
        printf("Would you like to continue? Y/N\n");
	    scanf(" %c", &cont);
    }

    if (cont == 'N' || cont == 'n'){
        exit(0);
    }


}

