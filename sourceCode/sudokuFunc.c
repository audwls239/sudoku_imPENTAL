#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"

void createNewGround(void){
    int i, j, k;
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
    int s0[3][3];
    int** s1;
    int** s2;
    int** s3;
    int** s4;
    int** s5;
    int** s6;
    int** s7;
    int** s8;
    int** temp;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++){
            s0[i][j] = createNumber();
        }
    }

    s1 = matrixProduct(x2, s0);
    s2 = matrixProduct(x1, s0);
    s3 = matrixProduct(s0, x1);

    temp = matrixProduct(x2, s0);
    s4 = matrixProductDP(temp, x1);

    temp = matrixProduct(x1, s0);
    s5 = matrixProductDP(temp, x1);

    s6 = matrixProduct(s0, x2);

    temp = matrixProduct(x2, s0);
    s7 = matrixProductDP(temp, x2);

    temp = matrixProduct(x1, s0);
    s8 = matrixProductDP(temp, x2);

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", s0[i][j]);
        }
        printf("  ");

        for(j = 0; j < 3; j++){
            printf("%d ", s1[i][j]);
        }
        printf("  ");

        for(j = 0; j < 3; j++){
            printf("%d ", s2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", s3[i][j]);
        }
        printf("  ");

        for(j = 0; j < 3; j++){
            printf("%d ", s4[i][j]);
        }
        printf("  ");

        for(j = 0; j < 3; j++){
            printf("%d ", s5[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", s6[i][j]);
        }
        printf("  ");

        for(j = 0; j < 3; j++){
            printf("%d ", s7[i][j]);
        }
        printf("  ");

        for(j = 0; j < 3; j++){
            printf("%d ", s8[i][j]);
        }
        printf("\n");
    }

    return;
}

/* 행렬의 곱 (배열, 배열) (완성) */
int** matrixProduct(int arr1[][3], int arr2[][3]){
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

/* 행렬의 곱 (더블 포인터, 배열) */
int** matrixProductDP(int** arr1, int arr2[][3]){
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

void createAnother(){
    int box[9][9];
    int i;

    for(i = 0; i < 9; i++)
        box[0][i] = createNumber();

    for(i = 0; i < 9; i++)
        printf("%d ", box[0][i]);
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