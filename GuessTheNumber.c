#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main (){
    int number,guessed=1,guess;
    srand (time(0));
    number = rand()%100+1;// random number generator

    do{
        printf("guess the number between 1 to 100\n");
        scanf("%d", &guess);

        if(guess>number){
            printf("lower the number!\n");
        }
        else if(guess<number){
            printf("higher the number!\n");
        }
        else{
            printf("you guessed the right number\n");
            printf("you guessed it in %d attempts\n",guessed);
        }

        guessed++;
        
    }while(guess!=number);

}