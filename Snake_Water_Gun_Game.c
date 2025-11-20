#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Welcome to the Snake-Water-Gun Game\n");
    char *choice[] = {"S", "W", "G"};
    srand(time(NULL));
    int randomIndex = rand()%3;
    char *computerChoice = choice[randomIndex];
    char Player;
    printf("To choose Snake Enter S\n");
    printf("To choose Water Enter W\n");
    printf("To choose Gun Enter G\n");
    printf("Enter Your Choice\n");
    scanf("%c", &Player);

    if(Player == 'S' && computerChoice[1]){
        printf("Computer Chose Water\n");
        printf("You Won! Snake will drink Water\n");
    }
    else if(Player == 'S' && computerChoice[2]){
        printf("Computer Chose Gun\n");
        printf("You Lose! Gun will shoot snake\n");
    }
    else if(Player == 'W' && computerChoice[0]){
        printf("Computer Chose Snake\n");
        printf("You Lose! Snake will drink Water\n");
    }
    else if(Player == 'W' && computerChoice[2]){
        printf("Computer Chose Gun\n");
        printf("You Won! Gun will sink in water\n");
    }
    else if(Player == 'G' && computerChoice[0]){
        printf("Computer Chose Snake\n");
        printf("You Won! Gun will shoot snake\n");
    }
    else if(Player == 'G' && computerChoice[1]){
        printf("Computer Chose Water\n");
        printf("You Lose! Gun will sink in water\n");
    }
    else{
        printf("It's a draw!\n");
    }

return 0;
}
