#ifndef STRUCT_H
#define STRUCT_H

typedef struct _matrix{     // 행렬
    int* mPtr;
} Matrix;

typedef struct _sudoku{
    Matrix* a_Box;     // 정답 스도쿠
    Matrix* f_Box;     // 유저 플레이 스도쿠(화면에 출력되는 스도쿠)
    Matrix* state;     // 입력 가능상태 배열(0 == 변경 불가능[최초 제시 숫자], 1 == 변경 가능, 2 == 변경 불가능[힌트])
    int gameOver;
    int offerNumAmount;
    int offerHint;
    int posX;
    int posY;
} Sudoku;

#endif