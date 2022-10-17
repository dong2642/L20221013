#include "Monster.h"
#include <iostream>
#include "MyEngine.h"
#include "Player.h"

using namespace std;

AMonster::AMonster()
{
	srand((unsigned int)time(nullptr));
	Shape = 'M';
	ZOrder = 45;
	CollisionType = ECollisionType::CollisionEnable;
	MyColor = { 0, 255, 255, 0 };

	ElapsedTime = 0;
	ExecuteTime = 500 + ((rand() % 200) - 100);

	LoadBMP("data/Slime.bmp");

	
}

AMonster::AMonster(int NewX, int NewY)
	: AMonster()
{
	X = NewX;
	Y = NewY;
}

AMonster::~AMonster()
{

}

void AMonster::Tick()
{

	ElapsedTime += GEngine->GetWorldDeltaSeconds();
	if (ExecuteTime > ElapsedTime)
	{
		return;
	}
	ElapsedTime = 0;

	int Direction = rand() % 4;

	switch (Direction)
	{
	case 0:
		Y--;
		if (!PredictCanMove())
		{
			Y++;
		}
		break;

	case 1:
		X--;
		if (!PredictCanMove())
		{
			X++;
		}
		break;

	case 2:
		Y++;
		if (!PredictCanMove())
		{
			Y--;
		}
		break;

	case 3:
		X++;
		if (!PredictCanMove())
		{
			X--;
		}
		break;
	}
}

bool AMonster::PredictCanMove()
{
	for (AActor* Actor : GEngine->GetAllActors())
	{
		if (X == Actor->X && Y == Actor->Y &&
			dynamic_cast<AMonster*>(Actor) == nullptr &&
			dynamic_cast<AMonster*>(Actor) != this)
		{
			if (CheckHit(Actor))
			{
				return false;
			}
		}
	}

	return true;
}

