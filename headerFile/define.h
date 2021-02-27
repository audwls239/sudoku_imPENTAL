#ifndef DEFINE_H
#define DEFINE_H

/* 키 입력 받을 때 쓸 것 */
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68
#define ENTER 10

#define KEY0 48
#define KEY1 49
#define KEY2 50
#define KEY3 51
#define KEY4 52
#define KEY5 53
#define KEY6 54
#define KEY7 55
#define KEY8 56
#define KEY9 57

/* 색깔 */
#define ANSI_COLOR_RED      "\x1b[31m"  // 기본 제공 숫자
#define ANSI_COLOR_YELLOW   "\x1b[33m"  // 힌트

#define ANSI_COLOR_GREEN    "\x1b[32m"  // 커서가 가리키는 슬롯
#define ANSI_COLOR_BLUE     "\x1b[34m"  // 사용자가 입력한 숫자를 가리킬 때

#define ANSI_COLOR_RESET    "\x1b[0m"   // 기본색 || 사용자가 입력한 숫자

#endif