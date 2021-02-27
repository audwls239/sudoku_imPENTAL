#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <termios.h>
#include <unistd.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuCreateFunc.h"
#include "../headerFile/print.h"
#include "../headerFile/system.h"
#include "../headerFile/sudokuGameFunc.h"
#include "../headerFile/define.h"

int main(void){
    Sudoku doku = {
        malloc(sizeof(Matrix) * 9),
        malloc(sizeof(Matrix) * 9),
        malloc(sizeof(Matrix) * 9),
        0, 0, 0, 0
    };

    /* 셋팅 구간 */
    set_ioconfig();         // getchar()는 키 입력받는 함수로 변경
    createNewBoard(&doku);  // 새로운 스도쿠 생성
    createField(&doku);     // 플레이 보드 생성


    int cmd;
    while(!doku.gameOver){
        /* 현재 화면 출력 */
        sudokuPrint(&doku);
        printf("X: %2d Y: %2d \n", doku.posX, doku.posY);
        
        usleep(100000);     // 선채로 죽었어...?
        system("clear");    // 화면 리셋

        /* 키 입력 받는 과속 단속 구간 */
        while(((cmd = getchar()) > 0)){
            /* 커서 이동 */
            if(cmd == 27 && getchar() == 91){
                switch(getchar()){
                    case UP:
                        doku.posY--;
                        posJudgement(&doku);
                        break;
                    case DOWN:
                        doku.posY++;
                        posJudgement(&doku);
                        break;
                    case LEFT:
                        doku.posX--;
                        posJudgement(&doku);
                        break;
                    case RIGHT:
                        doku.posX++;
                        posJudgement(&doku);
                        break;
                }
            }
            /* 숫자 입력 */
            else if(47 < cmd && cmd < 58){
                int i = 0;
                switch(cmd){
                    case KEY9: i++;
                    case KEY8: i++;
                    case KEY7: i++;
                    case KEY6: i++;
                    case KEY5: i++;
                    case KEY4: i++;
                    case KEY3: i++;
                    case KEY2: i++;
                    case KEY1: i++;
                    case KEY0:
                    if(doku.state[doku.posX / 3 + doku.posY / 3 * 3].mPtr[doku.posY % 3 * 3 + doku.posX % 3] == 1)
                        doku.f_Box[doku.posX / 3 + doku.posY / 3 * 3].mPtr[doku.posY % 3 * 3 + doku.posX % 3] = i;
                }
            }
            /* 하단 버튼 */
            else if(cmd == ENTER){
                if(doku.posY == 9){
                    switch(doku.posX){
                        /* 다 해떠염 */
                        case 0:
                            checkComplete(&doku);
                            break;
                        /* 힌트 주떼염 */
                        case 1:
                            requestHint(&doku);
                            break;
                    }
                }
            }
        }
        /* 과속 단속 구간 종료 */



    }

    free(doku.a_Box);
    free(doku.f_Box);
    free(doku.state);
    cleanup_io();
    return 0;
}