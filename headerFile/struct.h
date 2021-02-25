#ifndef STRUCT_H
#define STRUCT_H

typedef struct _matrix{     // 행렬
    int* mPtr;
} Matrix;

typedef struct _sudoku{
    Matrix a_Box[3][3];     // 정답 스도쿠
    Matrix f_Box[3][3];     // 유저 플레이 스도쿠
    Matrix state[3][3];     // 입력 가능상태 배열(0 == 입력 불가능, 1 == 입력 가능)
    int posX;
    int posY;
} Sudoku;

#endif