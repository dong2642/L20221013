#pragma once // 재정의하지말라고 선언


#ifndef __AACTOR_H__
#define __AACTOR_H__


class AActor
{

public:
	AActor();
	~AActor();

	void Draw();

	int X;
	int Y;

	char Shape;

};

#endif