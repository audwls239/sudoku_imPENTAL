#include "../headerFile/struct.h"

/* 쟛지먼트 데스노!! */
void posJudgement(Sudoku* doku){
    if(doku -> posX < 0)    // X좌표가 왼쪽 밖으로 나가면 복귀
        doku -> posX++;
    else if(8 < doku -> posX)    // X좌표가 오른쪽 밖으로 나가면 복귀
        doku -> posX--;
    else if(doku -> posY < 0)    // Y좌표가  밖으로 나가면 복귀
        doku -> posY++;
    else if(8 < doku -> posY)    // Y좌표가  밖으로 나가면 복귀
        doku -> posY--;
}