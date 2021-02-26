#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

int main(void){
    Sudoku doku = {
        malloc(sizeof(Matrix) * 9),
        malloc(sizeof(Matrix) * 9),
        malloc(sizeof(Matrix) * 9),
        0, 0
    };

    createNewBoard(&doku);

    createField(&doku);

    puts("a_Box");
    sudokuPrintTest33(doku.a_Box);
    puts("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ");
    puts("f_Box");
    sudokuPrintTest33(doku.f_Box);
    puts("─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ");
    puts("state");
    sudokuPrintTest33(doku.state);

    return 0;
}