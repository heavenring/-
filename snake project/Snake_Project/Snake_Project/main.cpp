/**	뱀게임 - 2019 인보 19 하계 팁 프로젝트
 *	렌더링 - 장문수
 *	키처리 - 임현섭
 *	로직구현 - 신진우, 김홍기
 *	아키텍팅 - 양정모
 *	양정모 파트
 */
#include <cstdio>
#include <Windows.h>
#include "util.h"
#include "render.h"
#include "key.h"
#include "logic.h"
char front_buff[10010],back_buff[10010];
void proc() {
	bool is_defeat = false;
	init();
	while (true) {
		get_screen_info(front_buff);
		render_screen(front_buff, back_buff);
		if (is_defeat)
			break;
		is_defeat = logical_action(get_key());
		Sleep(100);
	}
	game_end();
}
int main() {
	set_cursor(false);
	goto_xy(3, 5);
	set_color(BLACK, WHITE);
	printf("TEST");
	//init();
	//logical_action(-1);
	//get_screen_info(front_buff);
	//game_end();
	proc();
}