/**	logic.h
 *	������Ʈ�� �Լ����� �ִ� �������
 */
#ifndef __LOGIC_H__
#define __LOGIC_H__
#pragma once
#include <deque>
//Logic ��Ʈ���� �������� 2���� ��ǥ ����ü
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
 *	������ �ʱ� ���·� �����ִ� �Լ�
 *	return type - void
 *	x_size - cosnt int	//�������� x�� ũ��
 *	y_size - cosnt int	//�������� y�� ũ��
 *	high_score - const int	//������ �ְ� ���
 *
 *	size - const int	//���簢�� �������� �� ���� ũ��
 */
void init(const int x_size, const int y_size, const int high_score);
void init(const int size, const int high_score);
void init(const int high_score = 0);
/*	get_screen_info
 *	ȭ���� ǥ���ϴµ� �ʿ��� ������ ���ڿ��� �޾ƿ�
 *	return type - void
 *	buff - char*	//ȭ��� �ʿ��� ������ ��� ����
 */
void get_screen_info(char* buff);
/*	logical_action
 *	������ �������� ������ ��� ó���ϴ� �Լ�
 *	retyrb type - bool	//���� ���� ����
 *	key - int	//�Է¹��� Ű
 */
bool logical_action(int key);
/*	game_end
 *	������ ������ �� �ؾ��ϴ� ó���� �ϴ� �Լ�
 *	return type - int	//������ ������ ����� ����
 */
int game_end();

/*	move_snake
 *	���� ������������ �Ǵ��ϴ� �Լ�
 *	return type - int
 */
void move_snake();
bool is_snake_died();
void head_turning(int key);


void create_food();
bool is_eat_food();
void grow_snake();
#endif//__LOGIC_H__