#include <stdio.h>
#include <stdlib.h>  
#include <time.h>    

int main() {
    int randomNumber;

    
    srand(time(0));  

    
    randomNumber = rand() % 10 + 1;
int guess;
int attempt = 0;
printf("Guess the number between 1 to 10\n");

    do
    {   
        scanf("%d", &guess);
        attempt++;

        if(guess>randomNumber){
            printf("Too High, Try again!\n");
           
        }
        else if(guess<randomNumber){
            printf("Too Low, Try again!\n");
            
        }
        else if(guess == randomNumber){
            printf("You guessed it!! %d\n", randomNumber);
            printf("you took %d attempts to guess it right!", attempt);
            break;
        }
    } while (guess != randomNumber);
    
    return 0;
}
