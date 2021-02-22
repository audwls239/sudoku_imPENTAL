#ifndef STRUCT_H
#define STRUCT_H

typedef struct oneBox{
    int** small_Box;
} OneBox;

typedef struct _sudoku{
    OneBox big_Box[3][3];
} Sudoku;

#endif