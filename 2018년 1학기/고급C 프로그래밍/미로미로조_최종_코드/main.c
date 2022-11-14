#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Function.h"

#define MAX_SIZE 50


int main(void)
{

	int num, map;
	int count = 0;

	PLAYER player[MAX_SIZE];

	while (true)
	{
		system("cls");

		num = Menu();

		switch (num)
		{

		case 1: count = GetPlayer(player, count); break;

		case 2: Main_Start();
			showBoard(map = RandumNum());
			character_static(map, player, count);
			RANK(player, count); break;

		case 3: SEARCH(player, count); break;

		case 4: Store_Player(player, count); return 0;

		default: printf("잘못된 선택!!! \n");

		}

		system("pause");

	}

}