/**	logic_snake.cpp
 *	logic.h 의 뱀 함수 구현
 *	신진우 파트
 */
#include "logic.h"
#include "code_data.h"
Vec2 d_dir[] = { Vec2(0,-1),Vec2(-1,0),Vec2(0,1),Vec2(1,0) };
void move_snake() {
	snake.push_front(snake[0]+d_dir[direction]);
}
bool is_snake_died() {
	for (int i = 1; i < snake.size(); i++) {
		if (snake[0]==snake[1])
			return true;
	}
	if (0 > snake[0].x || snake[0].x >= x_size) return true;
	if (0 > snake[0].y || snake[0].y >= y_size) return true;
	return false;	//default
}
void head_turning(int key) {
	switch (key) {
	case UP: if(direction!=DOWN) direction = UP; break;
	case RIGHT: if(direction != LEFT) direction = RIGHT; break;
	case DOWN: if(direction != UP) direction = DOWN; break;
	case LEFT: if(direction != RIGHT) direction = LEFT; break;
	default: break;
	}
}