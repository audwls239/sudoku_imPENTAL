#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

#define firstBox doku -> a_Box[0][0].s_Box 

void createNewBoard(Sudoku* doku){
    /* Easy 모드 스도쿠 생성용 행렬 */
    int x1[3][3] = {
        {0, 0, 1},
        {1, 0, 0},
        {0, 1, 0}
    };
    int x2[3][3] = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    int i, j;
    int temp[3][3];
    // 0번 박스에 난수 생성
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            firstBox[i][j] = createNumber();
    }

    // [0][1], [0][2], [1][0]번 박스 생성
    matrixMul(doku -> a_Box[0][1].s_Box, x2, firstBox);
    matrixMul(doku -> a_Box[0][2].s_Box, x1, firstBox);
    matrixMul(doku -> a_Box[1][0].s_Box, firstBox, x1);

    // [1][1]번 박스 생성
    matrixMul(temp, x2, firstBox);
    matrixMul(doku -> a_Box[1][1].s_Box, temp, x1);

    // [1][2]번 박스 생성
    matrixMul(temp, x1, firstBox);
    matrixMul(doku -> a_Box[1][2].s_Box, temp, x1);

    // [2][0]번 박스 생성
    matrixMul(doku -> a_Box[2][0].s_Box, firstBox, x2);

    // [2][1]번 박스 생성
    matrixMul(temp, x2, firstBox);
    matrixMul(doku -> a_Box[2][1].s_Box, temp, x2);

    // [2][2]번 박스 생성
    matrixMul(temp, x1, firstBox);
    matrixMul(doku -> a_Box[2][2].s_Box, temp, x2);
}

/* 현 공간에 존재하지 않는 숫자 생성 */
int createNumber(void){
    static int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num, i;

    srand(time(NULL));

    while(1){
        num = (rand() % 9) + 1;

        for(i = 0; i < 9; i++){
            if(num == list[i]){
                list[i] = 0;
                return num;
            }
        }
    }
}

/* 행렬의 곱 */
void matrixMul(int resultMatrix[3][3], int arr1[3][3], int arr2[3][3]){
    int i, j, k;
    int result;

    /* 행렬의 곱 */
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            result = 0;

            for(k = 0; k < 3; k++){
                result += arr1[i][k] * arr2[k][j];
            }

            resultMatrix[i][j] = result;
        }
    }
}

void createField(Sudoku* doku){
    srand(time(NULL));

    int amount = rand() % 13 + 52;  // 삭제할 슬롯 갯수 랜덤 출력
    printf("amount: %d \n", 81 - amount);

    memcpy(doku -> f_Box, doku -> a_Box, sizeof(OneBox[3][3]));     // 플레이용 게임판 생성
    memset(doku -> state, 0, sizeof(OneBox[3][3]));                 // state 0으로 초기화

    int bigX, bigY, smallX, smallY;
    int count = 0;
    while(1){
        bigX = rand() % 3;
        bigY = rand() % 3;
        smallX = rand() % 3;
        smallY = rand() % 3;

        if(doku -> state[bigY][bigX].s_Box[smallY][smallX] == 0){
            doku -> state[bigY][bigX].s_Box[smallY][smallX] = 1;
            doku -> f_Box[bigY][bigX].s_Box[smallY][smallX] = 0;
            count++;
        }

        if(count == amount) break;
    }
}