/*********** Declaration*******
I hereby certify that no part of this assignment has been copied from
any other student’s work or from any other source. No part of the code
has been written/produced for me by another person or copied from any
other source.
I hold a copy of this assignment that I can produce if the original is
lost or damaged.
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int n;
int checkWin(char board[n][n]) {
    int check=0, count=0, i, j;
    // Check rows
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (board[i][j] != 'P') {
                break;
            }
        }
        if (j == n-1) {
            return 1;
        }
    }

    // Check columns
    for (j = 1; j < n; j++) {
        for (i = 1; i < n; i++) {
            if (board[i][j] != 'P') {
                break;
            }
        }
        if (i == n-1) {
            return 1;
        }
    }

    // Check diagonals
    for (i = 1; i < n; i++) {
        if (board[i][i] != 'P') {
            break;
        }
    }
    if (i == n-1) {
        return 1;
    }

    for (i = 1; i < n; i++) {
        if (board[i][n - i - 1] != 'P') {
            break;
        }
    }
    if (i == n-1) {
        return 1;
    }
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (board[i][j] == 'P') {
                if (i == n-1) {
                    check = 1;
                    continue;
                }
                // Check down
                if (i < n && board[i + 1][j] == 'P') {
                    if (i <= n - 2) {
                        check = 1;
                        count++;
                        //continue;
                    }
                    // Check down-right
                    if (j < n-1 && board[i + 1][j + 1] == 'P') {
                        check = 1;
                        count++;
                        //continue;
                    }
                    // Check down-left
                    else if (j > 1 && board[i + 1][j - 1] == 'P') {
                        check = 1;
                        count++;
                        //continue;
                    }
                }
                // Check right
                if (j < n-1 && board[i][j + 1] == 'P') {
                    check = 1;
                    //continue;
                }
                // Check left
                if (j > 0 && board[i][j - 1] == 'P') {
                    check = 1;
                    //continue;
                }
            }
        }
    }
    if(n<4){
        if(check==1)
            return 1;
        else
            return 0;
    }
    if(check==1 && count>=n-2)
        return 1;
    else
        return 0;


}


void showBoard(char board[n][n]){
    for (int i=0; i<n; i++){
        printf("\t|");
        for(int j=0; j<n; j++){
            if (board[i][j]>57 && board[i][j]<=68)
                printf(" %d|", board[i][j]-48);
            else
                printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int boardSize(int n){
    printf("Enter size of the board(3-20): ");
    scanf("%d", &n);
    n++;
    while((n>21) || (n<=3)){
        printf("\nInvalid Size\n");
        printf("Enter size of the board(3-20): ");
        scanf("%d", &n);
        n++;
    }
    return n;
}

int main()
{
    int i, j, k;
    time_t t;
    srand((unsigned) time(&t));

    void passerTurn(char board[n][n]){
        printf("\nPasser's Turn: ");
        printf("\nEnter v-index: ");
        scanf("%d", &i);
        printf("Enter h-index: ");
        scanf("%d", &j);
        if (board[i][j] == '-' && i<n && j<n) {
            board[i][j] = 'P';
        }
        else{
            printf("\nIndex occupied");
            passerTurn(board);
        }

    }

    void eaterTurn(char board[n][n]){
    //int i=1, j=1;
        printf("\nEater's Turn: ");
        printf("\nEnter h-index: ");
        scanf("%d", &i);
        printf("Enter v-index: ");
        scanf("%d", &j);
        if ((board[i][j] == '-' || board[i][j] == 'P')&& i<n && j<n) {
            board[i][j] = 'E';
        }
        else{
            printf("\nIndex occupied");
            eaterTurn(board);
        }

    }
    void randomEater(char board[n][n]){
        i = (rand() % (n-1))+1;
        j = (rand() % (n-1))+1;
        if ((board[i][j] == '-' || board[i][j] == 'P')&& i<n && j<n) {
            board[i][j] = 'E';
        }
        else{
            randomEater(board);
        }

    }
    void randomPasser(char board[n][n]){
        i = (rand() % (n-1))+1;
        j = (rand() % (n-1))+1;
        if (board[i][j] == '-' && i<n && j<n) {
            board[i][j] = 'P';
        }
        else{
            randomPasser(board);
        }
    }
    void linePasser(char board[n][n]){
       for (i=1; i<n; i++){
            for (j=1; j<n; j++){
                if (board[i][j] == '-' && i<n && j<n) {
                    board[i][j] = 'P';
                    i=n;
                    j=n;
                    break;
                }
            }
        }
    }
    void lineEater(char board[n][n]){
        for (i=1; i<n; i++){
            for (j=1; j<n; j++){
                if ((board[i][j] == '-' || board[i][j] == 'P')&& i<n && j<n) {
                    board[i][j] = 'E';
                    i=n;
                    j=n;
                    break;
                }
            }
        }
    }

    printf("\n\t---------- EATER GAME ----------\n\n");
    printf("\n\t\tHELLO PLAYER!!!\n\n");
    int c1, c2, c3, c4;

    printf("\nSelect game mode: ");
    printf("\n1. Single Player");
    printf("\n2. Multi Player");
    printf("\n3. Straight-line Player vs Random Player");
    printf("\n4. View Game Rules");
    printf("\n\tEnter Choice: ");
    do{
        scanf("%d", &c1);
    }while(c1>4|| c1<1);
    switch(c1){
        case 1:
            printf("\nSelect Role:\n\t 1. Passer\n\t 2. Eater\n");
            do{
                scanf("%d", &c2);
            }while(c2>2 || c2<1);
            break;
        case 2:

            printf("");
            break;
        case 3:
            printf("\nSelect role for Straight-line Player:\n\t\t 1. Passer\n\t\t 2. Eater\n");
            do{
                scanf("%d", &c2);
            }while(c2>2 && c2<1);
            break;
        case 4:
            printf("\nGame Rules");
            printf("\n\tThe game is played simultaneously by two players, each placing a marker of");
            printf("\n\teach placing an entry of their own initial ('P' and 'E' for Passer and Eater");
            printf("\n\trespectively into a cell that has not yet been occupied. When both players");
            printf("\n\tchoose the same cell to place an entry, the Eater's entry remains and the");
            printf("\n\tPasser's entry is eliminated. Otherwise, the entries remain on the board until");
            printf("\n\tthe game is completed. From the top to the bottom, the Passer seeks to form a");
            printf("\n\tconnected path of its own entries, which can go down, left, right, down-left, and");
            printf("\n\tdown-right, but cannot return. Once a connected path has been established, the");
            printf("\n\tPasser wins. The game then terminates. As long as the Passer does not have a");
            printf("\n\tconnected path and the board is full, the Eater wins.\n");
            printf("\n\n\tPress Enter to Continue...");
            //fflush ( stdout );
            getchar();
            while(getchar() != '\n');
            //scanf("\r");
            system("cls");
            main();
            break;
    }

    n = boardSize(n);

    char board[n][n];
    board[0][0] = 126;
    playagain:
    for (i=0; i<n; i++){
        int num = 49;
        for (j=1; j<n; j++){
            board[0][j] = num;
            num++;
        }
        num = 49;
        for (j=1; j<n; j++){
            board[j][0] = num;
            num++;
        }

    }
    for (i=1; i<n; i++){
        for(j=1; j<n; j++){
            board[i][j] = '-';
        }
    }

    showBoard(board);


    if(c1==1 && c2==1){
        for(i=1; i<n; i++){
            for(j=1; j<n; j++){
                if(board[i][j]=='-'){
                    passerTurn(board);
                    randomEater(board);
                    showBoard(board);
                    i=1, j=1;
                }
            }
        }
    }
    if(c1==1 && c2==2){
        for(i=1; i<n; i++){
            for(j=1; j<n; j++){
                if(board[i][j]=='-'){
                    eaterTurn(board);
                    randomPasser(board);
                    showBoard(board);
                    i=1, j=1;
                }
            }
        }
    }
    if(c1==2){
        for(i=1; i<n; i++){
            for(j=1; j<n; j++){
                if(board[i][j]=='-'){
                    passerTurn(board);
                    eaterTurn(board);
                    showBoard(board);
                    i=1, j=1;
                }
            }
        }
    }
    if(c1==3 && c2==1){
        for(i=1; i<n; i++){
            for(j=1; j<n; j++){
                if(board[i][j]=='-'){
                    linePasser(board);
                    randomEater(board);
                    //randomPasser(board);
                    showBoard(board);
                    i=1, j=1;
                }
            }
        }
    }
    if(c1==3 && c2==2){
        for(i=1; i<n; i++){
            for(j=1; j<n; j++){
                if(board[i][j]=='-'){
                    //randomEater(board);
                    randomPasser(board);
                    lineEater(board);
                    showBoard(board);
                    i=1, j=1;
                }
            }
        }
    }


    if (checkWin(board)== 1)
        printf("\nPasser Win");
    else
        printf("\nEater Win");


    int y = 0;
    printf("\n\t1. Play Again");
    printf("\n\t2. Main Menu\n");
    do{
        scanf("%d", &y);
    }while(y>2|| y<1);
    switch(y){
        case 1:
            goto playagain;
            break;
        case 2:
            system("cls");
            main();
            break;
    }




    return 0;
}
