
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

char Suare[] = {'0','1','2','3','4','5','6','7','8','9'};

int checkWin();
void drawBoard();

int main() {
    system("color 1f");//3-color of background,1-color of the txt
    int Player = 1, i, Choice;
    char Mark;//x or o

    do {
        drawBoard();
        Player = (Player % 2) ? 1 : 2;
        printf("Player %d, Enter the Value: ", Player);
        scanf("%d", &Choice);
        Mark = (Player == 1) ? 'X' : 'O';

        if (Choice >= 1 && Choice <= 9 && Suare[Choice] == ('0' + Choice))
            Suare[Choice] = Mark;
        else {
        printf("Invalid Choice! ");
            Player--;
            getch();
        }
        i = checkWin();
        Player++;
    } while (i == -1);

    drawBoard();
    if (i == 1) {
        printf("Player %d Won!\n", --Player);
    } else {
        printf("Game Draw\n");
    }
    getch();
    return EXIT_SUCCESS;
}

int checkWin() {
    if (Suare[1] == Suare[2] && Suare[2] == Suare[3])
        return 1;
    else if (Suare[4] == Suare[5] && Suare[5] == Suare[6])
        return 1;
     else if(Suare[7]==Suare[8] && Suare[8] == Suare[9])
        return 1;
    else if(Suare[1]==Suare[4] && Suare[4] == Suare[7])
        return 1;
     else if(Suare[2]==Suare[5] && Suare[5] == Suare[8])
        return 1;
     else if(Suare[3]==Suare[6] && Suare[6] == Suare[9])
        return 1;
     else if(Suare[1]==Suare[5] && Suare[5] == Suare[9])
        return 1;
     else if(Suare[3]==Suare[5] && Suare[5] == Suare[7])
        return 1;

    // Other winning conditions...
    else if (Suare[1] != '1' && Suare[2] != '2' && Suare[3] != '3' &&
             Suare[4] != '4' && Suare[5] != '5' && Suare[6] != '6' &&
             Suare[7] != '7' && Suare[8] != '8' && Suare[9] != '9')
        return 0;
    else
        return -1;
}

void drawBoard() {
    system("cls");
    printf("\nTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n\n");
    printf("\n");
    printf(" %c | %c | %c\n", Suare[1], Suare[2], Suare[3]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", Suare[4], Suare[5], Suare[6]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", Suare[7], Suare[8], Suare[9]);
    printf("\n");

    return EXIT_SUCCESS;
}











