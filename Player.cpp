#include "Player.h"
#include <iostream>
#include "MyEngine.h"

using namespace std;

APlayer::APlayer()
{
	Shape = 'P';
	ZOrder = 40;
	CollisionType = ECollisionType::CollisionEnable;
	MyColor = { 0, 255, 0, 0 };
	MyColorKey = { 255, 0, 255, 0 };

	LoadBMP("data/player.bmp");


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
	if (GEngine->MyEvent.type != SDL_KEYDOWN)
	{
		return;
	}

	switch (GEngine->MyEvent.key.keysym.sym)
	{
		case SDLK_w:
			Y--;
			if (!PredictCanMove())
			{
				Y++;
			}
			break;

		case SDLK_a:
			X--;
			if (!PredictCanMove())
			{
				X++;
			}
			break;

		case SDLK_s:
			Y++;
			if (!PredictCanMove())
			{
				Y--;
			}
			break;

		case SDLK_d:
			X++;
			if (!PredictCanMove())
			{
				X--;
			}
			break;

		case SDLK_ESCAPE:
			GEngine->QuitGame();

			break;
	}
}

bool APlayer::PredictCanMove()
{
	for (AActor* Actor : GEngine->GetAllActors())
	{
		if (X == Actor->X && Y == Actor->Y &&
			dynamic_cast<APlayer*>(Actor) == nullptr)
		{
			if (CheckHit(Actor))
			{
				return false;
			}
		}
	}

	return true;
}