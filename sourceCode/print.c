#include <stdio.h>
#include <stdlib.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

/* 스도쿠 출력 */
void sudokuPrint(Sudoku* doku){
    int bigX, bigY, smallX, smallY;
    int i;

    /* 천장 */
    printf("┏ ");
    for(i = 0; i < 11; i++){
        printf("━ ");
    }
    printf("┓ ");
    printf("\n");

    for(bigY = 0; bigY < 3; bigY++){
        for(smallY = 0; smallY < 3; smallY++){
            for(bigX = 0; bigX < 3; bigX++){
                printf("┃ ");
                for(smallX = 0; smallX < 3; smallX++){
                    if(doku -> posX == bigX * 3 + smallX && doku -> posY == bigY * 3 + smallY){
                        printf("□ ");
                    }
                    else{
                        if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX])
                            printf("%d ", doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        else
                            printf("  ");

                    }
                }
            }
            printf("┃\n");
        }
        if(bigY < 2){
            printf("┃ ");
            for(i = 0; i < 11; i++)
                printf("━ ");
            printf("┃");
            printf("\n");
        }
    }

    /* 바닥 */
    printf("┗ ");
    for(i = 0; i < 11; i++)
        printf("━ ");
    printf("┛ ");
    printf("\n");
}

/* 3x3 배열 출력 */
void matrixPrint(Matrix* mtx){
    int X, Y;

    for(Y = 0; Y < 3; Y++){
        for(X = 0; X < 3; X++)
            printf("%d ", mtx -> mPtr[Y * 3 + X]);
        printf("\n");
    }
    printf("\n");
}

/* 스도쿠 출력 테스트 */
void sudokuPrintTest33(Matrix* mtx){
    int bigX, bigY, smallX, smallY;
    int i = 0;

    for(bigY = 0; bigY < 3; bigY++){
        for(smallY = 0; smallY < 3; smallY++){
            for(bigX = 0; bigX < 3; bigX++){
                for(smallX = 0; smallX < 3; smallX++){
                    if(mtx[bigY * 3 + bigX].mPtr[smallY * 3 + smallX])
                        printf("%d ", mtx[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                    else
                        printf("  ");
                }
                printf("  ");
            }
            printf("\n");
        }
        printf("\n");
    }
}