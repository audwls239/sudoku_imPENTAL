#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

int main(void){
    Sudoku doku;
    doku.a_Box = malloc(sizeof(Matrix) * 9);
    doku.f_Box = malloc(sizeof(Matrix) * 9);
    doku.state = malloc(sizeof(Matrix) * 9);

    createNewBoard(&doku);
    matrixPrint(&doku.a_Box[0]);
    sudokuPrintTest33(&doku.a_Box);

    // createField(&doku);

    // puts("a_Box");
    // sudokuPrintTest33(doku.a_Box);
    // puts("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ");
    // puts("f_Box");
    // sudokuPrintTest33(doku.f_Box);
    // puts("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ");
    // puts("state");
    // sudokuPrintTest33(doku.state);

    return 0;
}