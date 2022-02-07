/**	key.h
 *	키 입력 파트의 함수들이 있는 헤더파일
 */
#ifndef __KEY_H__
#define __KEY_H__
#pragma once
#define SPECIAL_KEY -32
#include "code_data.h"
enum DIRECTION_KEY_CODE { _UP = 72, _LEFT = 75, _RIGHT = 77, _DOWN = 80 };
/*	get_key
 *	입력된 키를 처리
 *	return type - int
 */
int get_key();
#endif//__KEY_H__