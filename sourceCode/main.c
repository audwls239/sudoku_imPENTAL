#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <termios.h>
#include <unistd.h>

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

    int i = 0;
    while(1){
        usleep(100000);
        sudokuPrint(&doku);
        printf("%d \n", i++);
    }

    return 0;
}