#ifndef STRUCT_H
#define STRUCT_H

typedef struct _oneBox{
    int s_Box[3][3];        // 작은 박스
} OneBox;

typedef struct _sudoku{
    OneBox a_Box[3][3];     // 정답 배열
    OneBox f_Box[3][3];     // 플레이 배열
    OneBox state[3][3];     // 입력 가능상태 배열(0 == 입력 불가능, 1 == 입력 가능)
    int posX;
    int posY;
} Sudoku;

typedef struct _matrix{
    int width;
    int height;
    int** mPtr;
} Matrix;

#endif