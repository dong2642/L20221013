#include "Actor.h"
#include <iostream>
#include <windows.h>

using namespace std;

AActor::AActor() :
	X(1), Y(1), Shape(' ') //�ʱ�ȭ ����Ʈ
{
	/*X = 1;
	Y = 1;
	Shape = ' ';*/
}

AActor::~AActor()
{
}

void AActor::Draw()
{
	COORD Current;
	Current.X = X;
	Current.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Current);

	cout << Shape;
}
