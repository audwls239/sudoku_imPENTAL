#ifndef SUDOKU_FUNC_H
#define SUDOKU_FUNC_H

void createNewGround(void);

void createAnother();

int createNumber(void);

int** matrixProduct(int [][3], int [][3]);

int** matrixProductDP(int**, int [][3]);

#endif