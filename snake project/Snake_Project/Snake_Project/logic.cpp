/**	logic.cpp
 *	logic.h 함수 구현
 *	양정모 파트
 */
#include "logic.h"
#include "code_data.h"
std::deque<Vec2> snake;
int direction;
int score, high_score;
int x_size, y_size;
Vec2 food;

void init(const int x, const int y, const int h) {
	snake.clear();
	snake.push_back(Vec2(x, y) / 2);
	score = 0;
	high_score = h;//일단 보류
	x_size = x;
	y_size = y;
	create_food();
}
void init(const int s, const int h) {
	init(s, s, h);
}
void init(const int h) {
	init(11, h);
}
void get_screen_info(char* buff) {
	const char wall[] = "FF00";
	const char blank[] = "F000";
	const char up[] = "F001";
	const char left[] = "F002";
	const char down[] = "F003";
	const char right[] = "F004";
	const char body[] = "F005";
	auto get_pos = [](int x, int y) {return y * (x_size * 4 + 9) + x * 4;};
	for (int i = 1; i <= x_size; i++) 
		for (int j = 1; j <= y_size; j++) 
			memcpy(buff + get_pos(i, j), blank, 4);
	for (int i = 0; i <= x_size + 1; i++) {
		memcpy(buff + get_pos(i, 0), wall, 4);
		memcpy(buff + get_pos(i, y_size + 1), wall, 4);
	}
	for (int j = 0; j <= y_size + 1; j++) {
		memcpy(buff + get_pos(0, j), wall, 4);
		memcpy(buff + get_pos(x_size + 1, j), wall, 4);
	}
	for (auto iter : snake)
		memcpy(buff + get_pos(iter.x + 1, iter.y + 1), body, 4);
	for (int i = 1; i <= y_size + 1; i++) 
		buff[(x_size * 4 + 9) * i - 1] = 'n';
	const char* tgt;
	switch (direction) {
	case UP:tgt = up; break;
	case LEFT:tgt = left; break;
	case DOWN:tgt = down; break;
	case RIGHT:tgt = right; break;
	default:return;
	}
	memcpy(buff + get_pos(snake[0].x + 1, snake[0].y + 1), tgt, 4);
}
bool logical_action(int key) {
	if (is_eat_food()) {
		grow_snake();
		create_food();
	}
	head_turning(key);
	move_snake();
	return is_snake_died();
}
int game_end() {
	//일단 보류
	return score;
}