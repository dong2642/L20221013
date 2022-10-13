#include "Wall.h"
#include <iostream>

using namespace std;

AWall::AWall()
{
	Shape = '*';
}

AWall::AWall(int NewX, int NewY)
	: AWall()
{
	X = NewX;
	Y = NewY;
	
}

AWall::~AWall()
{

}

