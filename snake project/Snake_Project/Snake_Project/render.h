/**	render.h
 *	렌더링파트의 함수들이 있는 헤더파일
 */
#ifndef __RENDER_H__
#define __RENDER_H__
#pragma once
/*	render_screen
 *	더블 버퍼링 방식을 이용하여 화면을 렌더링
 *	return type - void
 *	buff1 - 화면에 렌더링 될 버퍼
 *	buff2 - 렌더링을 갱신하기 전의 화면의 상태를 담는 버퍼
 */
void render_screen(char* buff1,char* buff2);
#endif//__RENDER_H__