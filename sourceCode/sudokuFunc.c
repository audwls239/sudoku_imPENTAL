#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

#define firstBox doku -> big_Box[0][0].small_Box 

// Easy 모드 스도쿠 생성용 행렬
// x1[3][3] = 
//     {0, 0, 1}
//     {1, 0, 0}
//     {0, 1, 0}
// x2[3][3] = 
//     {0, 1, 0}
//     {0, 0, 1}
//     {1, 0, 0}

void createNewBoard(Sudoku* doku){
    int i, j, k;
    
    /* 곱하기용 행렬 생성 */
    int** x1 = malloc(sizeof(int*) * 3);
    int** x2 = malloc(sizeof(int*) * 3);

    for(i = 0; i < 3; i++){
        x1[i] = malloc(sizeof(int) * 3);
        x2[i] = malloc(sizeof(int) * 3);
    }

    for(i = 0; i < 3; i++){
        memset(x1[i], 0, sizeof(int) * 3);
        memset(x2[i], 0, sizeof(int) * 3);
    }
    
    x1[0][2] = 1;
    x1[1][0] = 1;
    x1[2][1] = 1;
    
    x2[0][1] = 1;
    x2[1][2] = 1;
    x2[2][0] = 1;
    
    // 모든 작은박스에 3x3 배열 할당
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            doku -> big_Box[i][j].small_Box = malloc(sizeof(int*) * 3);

            for(k = 0; k < 3; k++)
                doku -> big_Box[i][j].small_Box[k] = malloc(sizeof(int) * 3);
        }
    }
    
    // 0번 박스에 난수 생성
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            firstBox[i][j] = createNumber();
    }

    // [0][1], [0][2], [1][0]번 박스 생성
    doku -> big_Box[0][1].small_Box = matrixMul(x2, firstBox);
    doku -> big_Box[0][2].small_Box = matrixMul(x1, firstBox);
    doku -> big_Box[1][0].small_Box = matrixMul(firstBox, x1);

    // [1][1]번 박스 생성
    doku -> big_Box[1][1].small_Box = matrixMul(x2, firstBox);
    doku -> big_Box[1][1].small_Box = matrixMul(doku -> big_Box[1][1].small_Box, x1);

    // [1][2]번 박스 생성
    doku -> big_Box[1][2].small_Box = matrixMul(x1, firstBox);
    doku -> big_Box[1][2].small_Box = matrixMul(doku -> big_Box[1][2].small_Box, x1);

    // [2][0]번 박스 생성
    doku -> big_Box[2][0].small_Box = matrixMul(firstBox, x2);

    // [2][1]번 박스 생성
    doku -> big_Box[2][1].small_Box = matrixMul(x2, firstBox);
    doku -> big_Box[2][1].small_Box = matrixMul(doku -> big_Box[2][1].small_Box, x2);

    // [2][2]번 박스 생성
    doku -> big_Box[2][2].small_Box = matrixMul(x1, firstBox);
    doku -> big_Box[2][2].small_Box = matrixMul(doku -> big_Box[2][2].small_Box, x2);

    for(i = 0; i < 3; i++){
        free(x1[i]);
        free(x2[i]);
    }
    free(x1);
    free(x2);
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
int** matrixMul(int** arr1, int** arr2){
    int i, j, k;
    int result;
    int resultMatrix[3][3];

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

    /* 반환할 포인터 배열 생성 */
    int** new = malloc(sizeof(int*) * 3);
    for(i = 0; i < 3; i++){
        new[i] = malloc(sizeof(int) * 3);
    }

    /* 대입 */
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            new[i][j] = resultMatrix[i][j];
        }
    }

    return new;
}

void createField(Sudoku* doku){
    srand(time(NULL));

    int i, j, k;
    int amount = rand() % 13 + 52;  // 삭제할 슬롯 갯수 랜덤 출력
    memcpy(doku -> field_box, doku -> big_Box, sizeof(doku -> big_Box));    // 플레이할 게임판 생성

    OneBox state[3][3];             // 삭제된 슬롯 확인용
    memcpy(state, doku -> big_Box, sizeof(doku -> big_Box));    // 삭제된 슬롯 확인용

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            for(k = 0; k < 3; k++)
                memset(state[i][j].small_Box[k], 0, sizeof(int) * 3);
        }
    }

    puts("상태체크용 보드 출력");
    sudokuPrint(state);
}