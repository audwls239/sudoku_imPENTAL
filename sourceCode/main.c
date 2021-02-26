#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <termios.h>
#include <unistd.h>

#include "../headerFile/struct.h"
#include "../headerFile/sudokuFunc.h"
#include "../headerFile/print.h"
#include "../headerFile/system.h"
#include "../headerFile/gameFunc.h"

#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68

#define ENTER 10

#define key0 48
#define key1 49
#define key2 50
#define key3 51
#define key4 52
#define key5 53
#define key6 54
#define key7 55
#define key8 56
#define key9 57

int main(void){
    Sudoku doku = {
        malloc(sizeof(Matrix) * 9),
        malloc(sizeof(Matrix) * 9),
        malloc(sizeof(Matrix) * 9),
        0, 0
    };

    /* 셋팅 구간 */
    set_ioconfig();         // getchar()는 키 입력받는 함수로 변경
    createNewBoard(&doku);  // 새로운 스도쿠 생성
    createField(&doku);     // 플레이 보드 생성


    int cmd;
    while(1){
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
                    case key9: i++;
                    case key8: i++;
                    case key7: i++;
                    case key6: i++;
                    case key5: i++;
                    case key4: i++;
                    case key3: i++;
                    case key2: i++;
                    case key1: i++;
                    case key0:
                    if(doku.state[doku.posX / 3 + doku.posY / 3 * 3].mPtr[doku.posY % 3 * 3 + doku.posX % 3] == 1)
                        doku.f_Box[doku.posX / 3 + doku.posY / 3 * 3].mPtr[doku.posY % 3 * 3 + doku.posX % 3] = i;
                }
            }
            else if(cmd == ENTER)
                puts("ENTER");
            // else
            //     printf("%d ", cmd);
        }
        /* 과속 단속 구간 종료 */



        /* 현재 화면 출력 */
        sudokuPrint(&doku);
        printf("X: %2d Y: %2d \n", doku.posX, doku.posY);
    }

    return 0;
}