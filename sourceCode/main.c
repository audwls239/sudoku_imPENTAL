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

    createNewGround(&doku);

    sudokuPrint(&doku);

    printf("\n");

    return 0;
}