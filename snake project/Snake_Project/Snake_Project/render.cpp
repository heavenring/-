/**	render.cpp
 *	render.h �Լ� ����
 *	�幮�� ��Ʈ
 */
#include "util.h"
#include "render.h"
#include <cstdio>
#include <cstring>
/*	���� ����
 *	(��������2�ڸ�(00-FF) + ��¸�� ��ȣ 2�ڸ�(00-99)) * x�� ũ�� + n(�������� �˸��� ǥ��)
 *	ex)
 *	F005F005F005nF005F000F005nF005F005F005
 *	=
 *	����
 *	�ᡡ��
 *	����
 */
const char* shape[] = { "��", "��", "��", "��", "��","��" };
//buff2�ϰ� buff1�ϰ� �ٸ� �κи� ȭ�鿡 ����ؾ���.
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

	//�ǵ帮�� ���ÿ�
	strcpy_s(buff2, 10000, buff1);
}