/**	key.h
 *	Ű �Է� ��Ʈ�� �Լ����� �ִ� �������
 */
#ifndef __KEY_H__
#define __KEY_H__
#pragma once
#define SPECIAL_KEY -32
#include "code_data.h"
enum DIRECTION_KEY_CODE { _UP = 72, _LEFT = 75, _RIGHT = 77, _DOWN = 80 };
/*	get_key
 *	�Էµ� Ű�� ó��
 *	return type - int
 */
int get_key();
#endif//__KEY_H__