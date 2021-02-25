#include <stdio.h>
#include <stdlib.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

void sudokuPrint(Sudoku* doku){
    int bigX, bigY, smallX, smallY;
    int i, j;

    // 천장
    for(i = 0; i < 13; i++)
        printf("■ ");
    printf("\n");

    // 순서 bigY > smallY > bigX > smallX
    for(bigY = 0; bigY < 3; bigY++){
        for(smallY = 0; smallY < 3; smallY++){
            printf("■ ");
            for(bigX = 0; bigX < 3; bigX++){
                for(smallX = 0; smallX < 3; smallX++){
                    if(doku -> f_Box[bigY + 3 * bigX].mPtr[smallY + smallX * 3] == 0)
                        printf("  ");
                    else
                        printf("%d ", doku -> f_Box[bigY + 3 * bigX].mPtr[smallY + smallX * 3]);
                }
                printf("■ ");
            }
            printf("\n");
        }
        for(i = 0; i < 13; i++)
            printf("■ ");
        printf("\n");
    }
}

void matrixPrint(Matrix* mtx){
    int x, y;

    for(y = 0; y < 3; y++){
        for(x = 0; x < 3; x++)
            printf("%d ", mtx -> mPtr[y + 3 * x]);
        printf("\n");
    }
    printf("\n");
}


void sudokuPrintTest33(Matrix** mtx){
    int i, j, k;
    printf("%d ", mtx[] -> mPtr[]);
}