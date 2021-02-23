#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

int main(void){
    Sudoku doku;
    int i, j;

    createNewBoard(&doku);

    sudokuPrint(doku.big_Box);
    printf("\n");

    createField(&doku);

    sudokuPrint(doku.field_box);


    return 0;
}