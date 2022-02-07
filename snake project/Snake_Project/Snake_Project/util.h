/**	util.h
 *	�������� ������ �Լ����� ������ ���� ��
 */
#ifndef __UTIL_H__
#define __UTIL_H__
#pragma once
//�����ڵ�
enum color_code { BLACK = 0, BLUE, GREEN, LIGHT_BLUE, BROWN, PURPLE, GOLD, SILVER, GRAY, SKY_BLUE, GRACE, CLEAR_BLUE, RED, VIOLET, YELLOW, WHITE };
//goto_xy - Ŀ���� x,y�� �ű�
void goto_xy(short x_pos, short y_pos);
//set_color - �۲û��� ������ ����
void set_color(short font_color, short background_color);
//set_cursor - Ŀ�� ������ ����
void set_cursor(bool shown);
#endif//__UTIL_H__
