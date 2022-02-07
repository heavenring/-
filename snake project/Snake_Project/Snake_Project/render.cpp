/**	render.cpp
 *	render.h 함수 구현
 *	장문수 파트
 */
#include "util.h"
#include "render.h"
#include <cstdio>
#include <cstring>
/*	버퍼 정보
 *	(색상정보2자리(00-FF) + 출력모양 번호 2자리(00-99)) * x축 크기 + n(다음줄을 알리는 표시)
 *	ex)
 *	F005F005F005nF005F000F005nF005F005F005
 *	=
 *	■■■
 *	■　■
 *	■■■
 */
const char* shape[] = { "　", "▲", "◀", "▼", "▶","■" };
//buff2하고 buff1하고 다른 부분만 화면에 출력해야함.
void render_screen(char* buff1, char* buff2) {
	int x = 0, y = 0;
	auto parsing = [&buff1](int index) {
		if ('0' <= buff1[index] && buff1[index] <= '9')
			return buff1[index] - '0';
		if ('A' <= buff1[index] && buff1[index] <= 'F')
			return buff1[index] - 'A' + 10;
	};
	for (int i = 0; buff1[i];) {
		if (buff1[i] == 'n') {
			x = 0;
			y++;
			i++;
		}
		else {
			if (memcmp(buff1 + i, buff2 + i, 4) != 0) {
				int font_code = 0, back_code = 0;
				int shape_code_data[2] = { 0 };
				font_code = parsing(i);
				back_code = parsing(i + 1);
				for (int j = 0; j < 2; j++)
					shape_code_data[j] = parsing(i + 2 + j);
				int shape_code = shape_code_data[0] * 16 + shape_code_data[1];
				set_color(font_code, back_code);
				goto_xy(x, y);
				printf("%s", shape[shape_code]);
			}
			x++;
			i += 4;
		}
	}

	//건드리지 마시오
	strcpy_s(buff2, 10000, buff1);
}