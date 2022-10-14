#include "Player.h"
#include <iostream>
#include "Engine.h"


using namespace std;

APlayer::APlayer()
{
	Shape = 'P';
}

APlayer::APlayer(int NewX, int NewY)
	: APlayer()
{
	X = NewX;
	Y = NewY;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	cout << Engine::GetKeyCode() << endl;
}

//void APlayer::Input()
//{
//	cout << "Input" << endl;
//}
