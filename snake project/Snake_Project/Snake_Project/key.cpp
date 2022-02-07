/**	key.cpp
 *	key.h 함수 구현
 *	임현섭 파트
 */
#include "key.h"
#include "code_data.h"
#include <conio.h>
int judge_special_key(int in) {
	switch (in)
	{
	    case 72: 
		    return UP;
	    case 80: 
		    return DOWN;
	    case 75: 
		    return LEFT;
	    case 77: 
		    return RIGHT;
		default:;
	}
	return -1;//default: -1
}
int get_key() {
	int key;
	if (_kbhit())
	{
		key = _getch();
		switch (key)
		{
		case 224: 
			judge_special_key(_getch());
		    break; 
		case 'W':
		case 'w':
			return UP;
		case 'A':
		case 'a':
			return LEFT;
		case 'S':
		case 's':
			return DOWN;
		case 'D':
		case 'd':
			return RIGHT;
		default:;
		}
	}
    return -1;//default: -1
}