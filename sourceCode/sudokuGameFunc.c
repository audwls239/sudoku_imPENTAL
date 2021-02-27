#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#include "../headerFile/struct.h"

/* 쟛지먼트 데스노!! (커서 이동 판정이라는뜻) */
void posJudgement(Sudoku* doku){
    if(1 < doku -> posX && doku -> posY == 9)   // 힌트 버튼 or 체크 버튼 밖으로 나가면 복귀
        doku -> posX = 1;
    else if(doku -> posX < 0)    // X좌표가 왼쪽 밖으로 나가면 복귀
        doku -> posX++;
    else if(8 < doku -> posX)    // X좌표가 오른쪽 밖으로 나가면 복귀
        doku -> posX--;
    else if(doku -> posY < 0)    // Y좌표가  밖으로 나가면 복귀
        doku -> posY++;
    else if(9 < doku -> posY)    // Y좌표가  밖으로 나가면 복귀
        doku -> posY--;
}

/* SEX */
void checkComplete(Sudoku* doku){
    int state = 1;
    int i, j;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(doku -> a_Box[i].mPtr[j] != doku -> f_Box[i].mPtr[j]){
                state = 0;
                printf("NOPE! \n");
                usleep(1000000);
                return;
            }
        }
    }

    if(state){
        puts("C O N G R A T U L A T I O N");
        puts("Y O U  A R E  C O M P L E T E ! ! ! ");
        doku -> gameOver = 1;
        return;
    }
}

/* H I N T */
void requestHint(Sudoku* doku){
    srand(time(NULL));

    if(doku -> offerNumAmount + doku -> offerHint == 81)
        return;

    int bigX, bigY, smallX, smallY;
    while(1){
        bigX = rand() % 3;
        bigY = rand() % 3;
        smallX = rand() % 3;
        smallY = rand() % 3;

        if(doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] == 1){
            doku -> state[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] = 2;
            doku -> f_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX] = doku -> a_Box[bigY * 3 + bigX].mPtr[smallY * 3 + smallX];
            doku -> offerHint++;
            return;
        }
    }
}