#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

#define firstBox &doku -> a_Box[0][0]

/* 새로운 스도쿠 생성 */
void createNewBoard(Sudoku* doku){
    int i, j;
    Matrix temp;

    /* Easy 모드 스도쿠 생성용 행렬 */
    Matrix x1 = {3, 3, malloc(sizeof(int) * 9)};
    Matrix x2 = {3, 3, malloc(sizeof(int) * 9)};

    memset(x1.mPtr, 0, sizeof(int) * 9);
    memset(x2.mPtr, 0, sizeof(int) * 9);

    x1.mPtr[2] = 1;      // 0 0 1
    x1.mPtr[3] = 1;      // 1 0 0
    x1.mPtr[7] = 1;      // 0 1 0

    x2.mPtr[1] = 1;      // 0 1 0
    x2.mPtr[5] = 1;      // 0 0 1
    x2.mPtr[6] = 1;      // 1 0 0
    
    // 0번 박스에 난수 생성
    doku -> a_Box[0][0].mPtr = malloc(sizeof(int) * 9);
    for(i = 0; i < 9; i++)
        doku -> a_Box[0][0].mPtr[i] = createNumber();

    matrixPrint(&doku -> a_Box[0][0]);
    printf("\n");

    // [0][1], [0][2], [1][0]번 박스 생성
    doku -> a_Box[0][1].mPtr = matrixMul(&x2, firstBox);
    doku -> a_Box[0][2].mPtr = matrixMul(&x1, firstBox);
    doku -> a_Box[1][0].mPtr = matrixMul(firstBox, &x1);

    // [1][1]번 박스 생성
    temp.mPtr = matrixMul(&x2, firstBox);
    doku -> a_Box[1][1].mPtr = matrixMul(&temp, &x1);

    // [1][2]번 박스 생성
    temp.mPtr = matrixMul(&x1, firstBox);
    doku -> a_Box[1][2].mPtr = matrixMul(&temp, &x1);

    // [2][0]번 박스 생성
    doku -> a_Box[2][0].mPtr = matrixMul(firstBox, &x2);

    // [2][1]번 박스 생성
    temp.mPtr = matrixMul(&x2, firstBox);
    doku -> a_Box[2][1].mPtr = matrixMul(&temp, &x2);

    // [2][2]번 박스 생성
    temp.mPtr = matrixMul(&x1, firstBox);
    doku -> a_Box[2][2].mPtr = matrixMul(&temp, &x2);

    free(x1.mPtr);
    free(x2.mPtr);
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
int* matrixMul(Matrix* mtx1, Matrix* mtx2){
    int i, j;
    int* result = malloc(sizeof(int) * 9);

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            result[i * 3 + j] += mtx1 -> mPtr[i * 3 + j] * mtx2 -> mPtr[i + j * 3];
        }
    }

    return result;
}

void createField(Sudoku* doku){
    srand(time(NULL));

    int bigX, bigY, smallX, smallY;
    int count = 0;
    int amount = rand() % 14 + 51;  // 삭제할 슬롯 갯수 랜덤 출력
    printf("amount: %d \n", 81 - amount);

    for(bigY = 0; bigY < 3; bigY++){
        for(bigX = 0; bigX < 3; bigX++){
            doku -> f_Box[bigY][bigX].mPtr = malloc(sizeof(int) * 9);   // 유저가 입력할 수 있는 게임판 생성
            doku -> state[bigY][bigX].mPtr = malloc(sizeof(int) * 9);   // 처음 제시된 숫자 판단 여부용 게임판

            memcpy(doku -> f_Box[bigY][bigX].mPtr, doku -> a_Box[bigY][bigX].mPtr, sizeof(int) * 9);
            memset(doku -> state[bigY][bigX].mPtr, 0, sizeof(int) * 9);   // state 0으로 초기화
        }
    }    

    while(count != amount){
        bigX = rand() % 3;
        bigY = rand() % 3;
        smallX = rand() % 3;
        smallY = rand() % 3;

        if(doku -> state[bigY][bigX].mPtr[smallY + 3 * smallX] == 0){
            doku -> state[bigY][bigX].mPtr[smallY + 3 * smallX] = 1;
            doku -> f_Box[bigY][bigX].mPtr[smallY + 3 * smallX] = 0;
            count++;
        }
    }
}