/**	util.h
 *	여러가지 유용한 함수들을 선언해 놓는 곳
 */
#ifndef __UTIL_H__
#define __UTIL_H__
#pragma once
//색상코드
enum color_code { BLACK = 0, BLUE, GREEN, LIGHT_BLUE, BROWN, PURPLE, GOLD, SILVER, GRAY, SKY_BLUE, GRACE, CLEAR_BLUE, RED, VIOLET, YELLOW, WHITE };
//goto_xy - 커서를 x,y로 옮김
void goto_xy(short x_pos, short y_pos);
//set_color - 글꼴색과 배경색을 설정
void set_color(short font_color, short background_color);
//set_cursor - 커서 깜빡임 제어
void set_cursor(bool shown);
#endif//__UTIL_H__
