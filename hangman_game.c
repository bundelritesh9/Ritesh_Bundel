#include <stdio.h>

int main()
{
    char word[6] = {'M', 'E', 'N', 'T', 'O', 'R'};
    char underscore[6];
    char guess;
    int lives = 5;
    int correctguess;
    int allCorrect;

    printf("WELCOME TO THE HANGMAN CHALLENGE!\n");
    printf("You have 5 lives\n");
    printf("Please write Capital words only!\n");
    printf("Word : _ _ _ _ _ _\n");

    for (int i = 0; i < 6; i++){
        underscore[i] = '_';
    }

    while (lives > 0){
        correctguess = 0;
        printf("Enter Word : ");
        scanf(" %c", &guess);

        for (int i = 0; i < 6; i++){

            if (guess == word[i] && underscore[i] == '_'){
                underscore[i] = guess;
                correctguess = 1;
                
            }
            else if (guess != word[i] && underscore[i] != '_'){
                underscore[i] != guess;
                correctguess = 0;
                
            }
        }

        printf("Word: ");
        for (int i = 0; i < 6; i++){
            printf("%c ", underscore[i]);
        }
        printf("\n");

        if(correctguess == 0){
            lives--; 
            printf("Wrong guess! Lives left: %d\n", lives);
        }

        allCorrect = 1;
        for (int i = 0; i < 6; i++){
            if (underscore[i] != word[i]){
                allCorrect = 0;
                break;
            }
        }

        if(allCorrect){
            printf("Congratulations! You Won!\n");
            return 0;
        }

    }

    printf("You lost!, The Word was %c%c%c%c%c%c", word[0], word[1], word[2], word[3], word[4], word[5]);
    return 0;
}
