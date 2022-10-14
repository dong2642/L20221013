#include <iostream>
#include <fstream>
#include "MyEngine.h"


class StaticClass
{
public:
	static int Gold;

	static void Add()
	{
	/*	Help = 10;*/
	}
	void Inner()
	{
		StaticClass::Gold = 1;
	}
};

int StaticClass::Gold = 1;

int main()
{

	MyEngine* E = new MyEngine();

	E->Initialize();

	E->Run();

	E->Terminalize();

	
	return 0;
}