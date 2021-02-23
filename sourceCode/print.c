#include <stdio.h>
#include <stdlib.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

void sudokuPrint(OneBox matrix[3][3]){
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
                    printf("%d ", matrix[bigY][bigX].small_Box[smallY][smallX]);
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