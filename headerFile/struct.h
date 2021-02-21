#ifndef STRUCT_H
#define STRUCT_H

typedef struct oneBox{
    int little_Box[3][3];
} OneBox;

typedef struct sudoku{
    OneBox big_Box[3][3];
} SudoKu;

#endif