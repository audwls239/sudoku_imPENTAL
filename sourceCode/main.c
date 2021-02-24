#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

int main(void){
    Sudoku* doku = malloc(sizeof(Sudoku));

    createNewBoard(doku);
    createField(doku);

    sudokuPrint(doku);

    free(doku);
    return 0;
}