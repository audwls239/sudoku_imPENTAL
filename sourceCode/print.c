#include <stdio.h>
#include <stdlib.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuCreateFunc.h"
#include "../headerFile/print.h"
#include "../headerFile/define.h"


/* 스도쿠 출력 */
void sudokuPrint(Sudoku* doku){
    int bigX, bigY, smallX, smallY;
    int i;

    /* 천장 출력 */
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
                    /* 커서가 가리키는 슬롯 */
                    if(doku -> posX == bigX * 3 + smallX
                    && doku -> posY == bigY * 3 + smallY){
                        /* 커서가 가리킴 && 변경 가능 슬롯 && 값이 있음 (GREEN) */
                        if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] != 0
                            && doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 1)
                            printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET, doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        /* 커서가 가리킴 && 변경 불가능 슬롯 (GREEN) */
                        else if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] != 0
                        && doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 0)
                            printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET, doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        /* 커서가 가리킴 && 힌트 받은 슬롯 (GREEN) */
                        else if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] != 0
                            && doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 2)
                            printf(ANSI_COLOR_GREEN "%d " ANSI_COLOR_RESET, doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        /* 커서가 가리킴 && 변경 가능 슬롯 && 값이 없음 (GREEN) */
                        else
                            printf(ANSI_COLOR_GREEN "□ " ANSI_COLOR_RESET);
                    }
                    /* 커서가 가리키지 않는 슬롯 */
                    else{
                        /* 변경 가능 슬롯 (RESET) */
                        if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] != 0
                        && doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 1)
                            printf("%d ", doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        /* 변경 불가능 슬롯 (RED) */
                        else if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] != 0
                            && doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 0)
                            printf(ANSI_COLOR_RED "%d " ANSI_COLOR_RESET, doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        /* 힌트 받은 슬롯 (YELLOW) */
                        else if(doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] != 0
                            && doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 2)
                            printf(ANSI_COLOR_YELLOW "%d " ANSI_COLOR_RESET, doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX]);
                        /* 빈칸 == 0 */
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

    /* 완성 버튼 && 힌트 버튼 */
    printf("┃ ");
    if(doku -> posX == 0 && doku -> posY == 9)
        printf(ANSI_COLOR_BLUE);
    printf("CHECK ");
    printf(ANSI_COLOR_RESET);
    printf("┃ ");
    if(doku -> posX == 1 && doku -> posY == 9)
        printf(ANSI_COLOR_BLUE);
    printf(" HINT ");
    printf(ANSI_COLOR_RESET);
    printf("┃ \n");

    /* 받은 힌트 갯수 */
    printf("┃ HINT:       %2d┃ \n", doku -> offerHint);
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