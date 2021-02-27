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
        0, 0, 0, 0, 0
    };

    /* 셋팅 구간 */
    set_ioconfig();         // getchar()는 키 입력받는 함수로 변경
    createNewBoard(&doku);  // 새로운 스도쿠 생성
    createField(&doku);     // 플레이 보드 생성

    int i = 0;
    int cmd;

    /* 시작 화면 출력 */
    system("clear");
    puts("┏ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┓ ");
    puts("┃       ┃       ┃       ┃");
    puts("┃   S   ┃   U   ┃   D   ┃");
    puts("┃       ┃       ┃       ┃");
    puts("┃ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┃");
    puts("┃       ┃       ┃       ┃");
    puts("┃   O   ┃   K   ┃   U   ┃");
    puts("┃       ┃       ┃       ┃");
    puts("┃ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┃");
    puts("┃       ┃       ┃       ┃");
    puts("┃  MADE ┃   BY  ┃ im    ┃");
    puts("┃       ┃       ┃ PENTAL┃");
    puts("┗ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ┛ ");

    puts("[MOVE]: → ↑ ↓ ←");
    puts("[INPUT NUMBER]: 0 ~ 9");
    puts("[ENTER]: ENTER");
    puts("");
    puts("Press Enter Key to Start");

    while(getchar() != 10);

    while(!doku.gameOver){
        usleep(100000);     // 딜레이

        system("clear");    // 화면 리셋
        sudokuPrint(&doku); // 화면 출력

        /* 키 입력 받는 구간 */
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
            /* 커서가 가리키는 슬롯에 입력 */
            else if(47 < cmd && cmd < 58){
                i = 0;
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
            /* 게임 하단 버튼 */
            else if(cmd == ENTER){
                if(doku.posY == 9){
                    switch(doku.posX){
                        /* 완성 체크 */
                        case 0:
                            checkComplete(&doku);
                            break;
                        /* 힌트 제공 */
                        case 1:
                            requestHint(&doku);
                            break;
                    }
                }
            }
        }
        /* 키 입력 구간 종료 */
    }

    for(i = 0; i < 9; i++){
        free(doku.a_Box[i].mPtr);
        free(doku.f_Box[i].mPtr);
        free(doku.state[i].mPtr);
    }
    free(doku.a_Box);
    free(doku.f_Box);
    free(doku.state);
    cleanup_io();
    return 0;
}