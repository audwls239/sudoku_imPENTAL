#ifndef STRUCT_H
#define STRUCT_H

typedef struct _oneBox{
    int** small_Box;
} OneBox;

typedef struct _sudoku{
    OneBox big_Box[3][3];
    OneBox field_box[3][3];
} Sudoku;

#endif