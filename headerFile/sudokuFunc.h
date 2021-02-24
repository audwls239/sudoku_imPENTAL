#ifndef Sudoku_FUNC_H
#define Sudoku_FUNC_H

void createNewBoard(Sudoku* doku);  // 새로운 스도쿠 생성

int createNumber(void);             // 해당 배열에 존재하지 않는 숫자 생성

void matrixMul(int resultMatrix[3][3], int arr1[3][3], int arr2[3][3]); // 행렬의 곱

void createField(Sudoku* doku);     // 실제로 플레이할 게임판 생성

#endif