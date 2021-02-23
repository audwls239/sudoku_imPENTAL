#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"

int main(void){
    Sudoku doku;

    createNewBoard(&doku);

    puts("정답 출력");
    sudokuPrint(doku.big_Box);
    printf("\n");

    createField(&doku);

    puts("플레이용 보드 출력");
    sudokuPrint(doku.field_box);

    return 0;
}