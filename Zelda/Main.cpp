#include "pch.h"
// #include "./test.cpp"
#include "Zelda.h"
#include <windows.h>
int main()
{
	Game *game = new Game();
	game->Play();

	system("PAUSE");
	return 0;
}
