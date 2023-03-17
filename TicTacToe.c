#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char arr[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int player = 0;


void show()
{
    printf("\t\t*********TicTacToe*********\n\n");
    printf("\t\t\t %c | %c | %c \n", arr[0], arr[1], arr[2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", arr[3], arr[4], arr[5]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", arr[6], arr[7], arr[8]);
}

void start_play()
{
    int pos;
    if (player == 0)
    {
    label:
        printf("Enter position player 1: ");
        scanf("%d", &pos);

        if (arr[pos - 1] == 'X' || arr[pos - 1] == 'O')
        {
            printf("Alraedy placed! try different place\n");
            goto label;
        }
        else
        {
            for (int i = 1; i <= strlen(arr); i++)
            {
                if (pos == i)
                {
                    arr[i - 1] = 'X';
                }
            }
        }
        player = 1;
    }
    else
    {
    label1:
        printf("Enter position player 2: ");
        scanf("%d", &pos);

        if (arr[pos - 1] == 'X' || arr[pos - 1] == 'O')
        {
            printf("Alraedy placed! try different place\n");
            goto label1;
        }
        else
        {
            for (int i = 1; i <= strlen(arr); i++)
            {
                if (pos == i)
                {
                    arr[i - 1] = 'O';
                }
            }
        }
        player = 0;
    }
}

int checkWinner()
{
    if ((arr[0] == 'X') && (arr[1] == 'X') && (arr[2] == 'X') || (arr[0] == 'X') && (arr[3] == 'X') && (arr[6] == 'X') || (arr[0] == 'X') && (arr[4] == 'X') && (arr[8] == 'X'))
    {
        return 1;
    }
    else if ((arr[0] == 'O') && (arr[1] == 'O') && (arr[2] == 'O') || (arr[0] == 'O') && (arr[3] == 'O') && (arr[6] == 'O') || (arr[0] == 'O') && (arr[4] == 'O') && (arr[8] == 'O'))
    {
        return 2;
    }
    else if ((arr[1] == 'X') && (arr[4] == 'X') && (arr[7] == 'X'))
    {
        return 1;
    }
    else if ((arr[1] == 'O') && (arr[4] == 'O') && (arr[7] == 'O'))
    {
        return 2;
    }
    else if ((arr[2] == 'X') && (arr[5] == 'X') && (arr[8] == 'X') || (arr[2] == 'X') && (arr[4] == 'X') && (arr[6] == 'X'))
    {
        return 1;
    }
    else if ((arr[2] == 'O') && (arr[5] == 'O') && (arr[8] == 'O') || (arr[2] == 'O') && (arr[4] == 'O') && (arr[6] == 'O'))
    {
        return 2;
    }
    else if ((arr[3] == 'X') && (arr[4] == 'X') && (arr[5] == 'X'))
    {
        return 1;
    }
    else if ((arr[3] == 'O') && (arr[4] == 'O') && (arr[5] == 'O'))
    {
        return 2;
    }
    else if ((arr[6] == 'O') && (arr[7] == 'O') && (arr[8] == 'O'))
    {
        return 1;
    }
    else if ((arr[6] == 'O') && (arr[7] == 'O') && (arr[8] == 'O'))
    {
        return 2;
    }
    else
    {
        return -1;
    }
}
void reset(){
   arr[0] = '1';
   arr[1] = '2';
   arr[2] = '3';
   arr[3] = '4';
   arr[4] = '5';
   arr[5] = '6';
   arr[6] = '7';
   arr[7] = '8';
   arr[8] = '9';
}
void rules(){
    printf("\n\n-> Player 1 symbol is 'X' \n");
    printf("-> Player 2 symbol is 'O'\n");
    printf("-> In the first match Player 1 will get the chance first\n");
    printf("-> In the second match Player 2 will get the chance first \n");
    printf("-> In the third match Player 1 will again get the chance first and so on \n\n\n");
}
void main()
{
    char play = 'y';

    while (play == 'y')
    {
        int res;
        int count = 0;
        show();
        rules();
        do
        {
            start_play();
            system("cls");
            show();
            res = checkWinner();
            count++;
            if (count == 9)
                break;
        } while (res == -1);

        if (res == 1 && count <= 9)
        {
            printf("\n\n\t\t\tYAY!Player 1 won the match\n");
        }
        else if (res == 2 && count <= 9)
        {
            printf("\n\n\t\t\tYAY!Player 2 won the match\n");
        }
        else
        {
            printf("\n\n\t\t\tMatch Draw\n");
        }
        printf("want to play again? Press 'y' or 'n'\n");
        fflush(stdin);
        scanf("%c",&play);
        reset();
    }
}