/**	logic.h
 *	로직파트의 함수들이 있는 헤더파일
 */
#ifndef __LOGIC_H__
#define __LOGIC_H__
#pragma once
#include <deque>
//Logic 파트에서 쓰기위한 2차원 좌표 구조체
typedef struct Vec2 {
	int x, y;
	Vec2() : x(0), y(0) {}
	Vec2(int x, int y) : x(x), y(y) {}
	struct Vec2 operator+(Vec2 desc) {
		return Vec2(x + desc.x, y + desc.y);
	}
	struct Vec2 operator-() {
		return Vec2(-x, -y);
	}
	struct Vec2 operator-(Vec2 desc) {
		return Vec2(x - desc.x, y - desc.y);
	}
	struct Vec2 operator*(int k) {
		return Vec2(x * k, y * k);
	}
	struct Vec2 operator/(int k) {
		return Vec2(x / k, y / k);
	}
	bool operator==(Vec2 desc) {
		return this->x == desc.x && this->y == desc.y;
	}
}Vec2;
extern std::deque<Vec2> snake;
extern int direction;
extern int score, high_score;
extern int x_size, y_size;
extern Vec2 food;
/*	init
 *	게임을 초기 상태로 돌려주는 함수
 *	return type - void
 *	x_size - cosnt int	//게임판의 x축 크기
 *	y_size - cosnt int	//게임판의 y축 크기
 *	high_score - const int	//게임의 최고 기록
 *
 *	size - const int	//정사각형 게임판의 한 변의 크기
 */
void init(const int x_size, const int y_size, const int high_score);
void init(const int size, const int high_score);
void init(const int high_score = 0);
/*	get_screen_info
 *	화면을 표현하는데 필요한 정보를 문자열에 받아옴
 *	return type - void
 *	buff - char*	//화면상에 필요한 정보를 담는 버퍼
 */
void get_screen_info(char* buff);
/*	logical_action
 *	로직에 여러가지 동작을 묶어서 처리하는 함수
 *	retyrb type - bool	//게임 오버 여부
 *	key - int	//입력받은 키
 */
bool logical_action(int key);
/*	game_end
 *	게임이 끝났을 때 해야하는 처리를 하는 함수
 *	return type - int	//게임이 끝났을 당시의 점수
 */
int game_end();

/*	move_snake
 *	뱀이 움직였는지를 판단하는 함수
 *	return type - int
 */
void move_snake();
bool is_snake_died();
void head_turning(int key);


void create_food();
bool is_eat_food();
void grow_snake();
#endif//__LOGIC_H__