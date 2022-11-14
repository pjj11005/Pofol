#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

#include "Function.h"
#include "Map.h"




/* 맵 함수 */


int RandumNum(void)
{
	srand((int)time(NULL));
	return rand() % Map_Count;
}

void Main_Start(void)
{
	removeCursor();
	system("cls");

	int width = POINT_X, heigth = POINT_Y;
	int idx = 15;
	int s = 0, w = -1, wid = 2, hei = 1, val = 0;

	for (int j = 0;j < 2;j++)
	{
		for (int i = 0; i < idx;i++) // 가로 단위 그림 
		{
			val++;
			w = w + wid;
			setCursor(width + w, heigth + s);
			TextColor(i + 1);
			printf("☆");
			Sleep(100);
		}
		idx = idx - 1;

		for (int i = 0; i < idx; i++) // 세로 단위 그림
		{
			val++;
			s = s + hei;
			setCursor(width + w, heigth + s);
			TextColor(i + 1);
			printf("☆");
			Sleep(100);
		}
		wid = wid * -1;
		hei = hei * -1;
	}

	setCursor(POINT_X + 12, POINT_Y + 6);
	printf("재미있는");

	setCursor(POINT_X + 12, POINT_Y + 7);
	printf("미로미로");
	Sleep(2000);

	Remover(POINT_X, POINT_Y, MAZE_BOARD_WIDTH);
}

void showBoard(int randum)
{
	int x, y;
	WinFunc(1);
	removeCursor();

	setCursor(POINT_X, POINT_Y);

	COORD cur = getCursor();

	for (y = 0; y < MAZE_BOARD_HEIGHT; y++)
	{
		for (x = 0; x < MAZE_BOARD_WIDTH; x++)
		{
			setCursor(cur.X + (x * 2), cur.Y + y);    // 옆으로 2칸, 밑으로 1칸

			if (maze[randum][y][x] == '1')
				printf("▣");
			if (maze[randum][y][x] == 'x')
				printf("♥");
			if (maze[randum][y][x] == 'Q')
				printf("◈");
		}
	}
	setCursor(cur.X, cur.Y);
}


/* 문제 함수 */


void Question(int num)
{
	setCursor(0, POINT_Y);

	switch (num)
	{
	case 0:
		printf("10 + 20 + 30 + 40? "); break;
	case 1:
		printf("레드벨벳의 멤버 수는? "); break;
	case 2:
		printf("BTS의 멤버 수는? "); break;
	case 3:
		printf("문어의 다리 수는? "); break;
	case 4:
		printf("문재인은 몇대 대통령인가? "); break;
	case 5:
		printf("짱구의 나이는? "); break;

	default: break;

	}

}

int Answer(int num)
{
	int answer;

	scanf("%d", &answer);
	while (getchar() != '\n');

	switch (num)
	{
	case 0:
		if (answer == 100)
			return 1;
		else
			return 0;
	case 1:
		if (answer == 5)
			return 1;
		else
			return 0;
	case 2:
		if (answer == 7)
			return 1;
		else
			return 0;
	case 3:
		if (answer == 8)
			return 1;
		else
			return 0;
	case 4:
		if (answer == 19)
			return 1;
		else
			return 0;
	case 5:
		if (answer == 5)
			return 1;
		else
			return 0;

	default: return 0;
	}
}


/* 메뉴 함수 */


int Menu(void)
{

	Team_Player();

	removeCursor();
	WinFunc(0);

	int num;
	int width = POINT_X, heigth = POINT_Y;
	int idx = 15;
	int s = 0, w = -1, wid = 2, hei = 1, val = 0;

	for (int j = 0;j < 2;j++)
	{
		for (int i = 0; i < idx;i++) // 가로 단위 그림 
		{
			val++;
			w = w + wid;
			setCursor(width + w, heigth + s);
			printf("☆");
		}
		idx = idx - 1;

		for (int i = 0; i < idx; i++) // 세로 단위 그림
		{
			val++;
			s = s + hei;
			setCursor(width + w, heigth + s);
			printf("☆");
		}
		wid = wid * -1;
		hei = hei * -1;
	}

	setCursor(POINT_X + 10, POINT_Y + 5);
	printf("1. 정보 입력");
	setCursor(POINT_X + 10, POINT_Y + 6);
	printf("2. 게임 시작 \n");
	setCursor(POINT_X + 10, POINT_Y + 7);
	printf("3. 랭킹 확인 \n");
	setCursor(POINT_X + 10, POINT_Y + 8);
	printf("4. 게임 종료 \n\n");
	setCursor(POINT_X + 10, POINT_Y + 10);
	printf("메뉴 선택 : ");


	scanf("%d", &num);
	while (getchar() != '\n');

	return num;

}

void Team_Player(void)
{
	setCursor(POINT_X + 46, POINT_Y + 16);
	printf("팀명 : 미로미로");
	setCursor(POINT_X + 46, POINT_Y + 18);
	printf("미디어영상학부 2015906051 신현석");
	setCursor(POINT_X + 46, POINT_Y + 19);
	printf("정보융합학부   2017204044 백승준");
	setCursor(POINT_X + 46, POINT_Y + 20);
	printf("정보융합학부   2018204016 이진우");
	setCursor(POINT_X + 46, POINT_Y + 21);
	printf("정보융합학부   2018204022 최승환 ");
	setCursor(POINT_X + 46, POINT_Y + 22);
	printf("정보융합학부   2018204002 박정재");
}


/* 커서 함수 */


void removeCursor(void)
{

	CONSOLE_CURSOR_INFO cur;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);
	cur.bVisible = 0;     //1이면 깜빡이고, 0이면 깜빡이지 않음
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cur);

}

void setCursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);   //콘솔 위치 설정

}

COORD getCursor(void)  //콘솔 위치 받기
{
	COORD curPoint;
	CONSOLE_SCREEN_BUFFER_INFO pos;    //콘솔 화면 버퍼에 대한 정보
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pos);  //콘솔 위치 반환
	curPoint.X = pos.dwCursorPosition.X;
	curPoint.Y = pos.dwCursorPosition.Y;

	return curPoint;
}


/* 캐릭터 함수 */


void showCharacter(void)
{
	COORD cur = getCursor();

	printf("★");

	setCursor(cur.X, cur.Y);
}


/* 시간 함수 */


double Start_Time(void)
{
	return clock();
}
void End_Time(PLAYER * player, double start_time, int count)
{
	clock_t end_time = clock();

	(player + count - 1)->score = (double)(end_time - start_time) / CLOCKS_PER_SEC;
}


/* 기타 함수 */


void Remover(int X, int Y, int size)
{
	setCursor(X, Y);

	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
			printf("       ");
	}
}

void WinFunc(int color)
{
	system("title MIROMIRO");

	switch (color)
	{
	case 0:  system("color 07"); break;
	case 1:  system("color B4"); break;
	}
}

void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
