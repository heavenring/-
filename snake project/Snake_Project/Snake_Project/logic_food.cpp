/**	logic_snake.cpp
 *	logic.h ÀÇ ¹ì ÇÔ¼ö ±¸Çö
 *	±èÈ«±â ÆÄÆ®
 */
#include "logic.h"
#include <stdlib.h>
using namespace std;
bool is_eat_food() {
	return snake[0] == food;
	
}
void grow_snake() {
	
	snake.push_back(snake.back());
	
}
void create_food() {
	deque<deque<int>> map(x_size);
	for (auto& i : map)
		i = deque<int>(y_size, 0);
	for (int i = 0; i < snake.size(); i++) {
		map[snake[i].x][snake[i].y] = 1;
	}
	deque<Vec2> target;
	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			if (map[i][j] == 0)
				target.push_back(Vec2(i,j));

		}
	}
	food=target[rand() % target.size()];
}
		

		