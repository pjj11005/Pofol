#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>

#include "Function.h"
#include "Map.h"


/* ���� �˰��� */


void character_static(int randum, PLAYER * player, int count)

{
	int value = true;

	double start_time = Start_Time();

	int kb;
	int delay = 10;
	setCursor(POINT_X, POINT_Y + 1);  //�ɸ��ͽ�����ġ

	while (value)
	{

		while (!_kbhit())  //Ű���� �Է� �˻�(�Է½� 0�� �ƴ� ��)
		{
			showCharacter();
			Sleep(delay); //�����̴� DELAY�� 0.01��
		}

		kb = _getch(); //�Է��Լ� (�ֿܼ� ��Ÿ���� ����)

		switch (kb)
		{
		case UP: value = RemoveCharacter_Set(0, -1, randum, player, start_time, count); break;

		case DOWN: value = RemoveCharacter_Set(0, 1, randum, player, start_time, count); break;

		case RIGHT: value = RemoveCharacter_Set(2, 0, randum, player, start_time, count); break;

		case LEFT: value = RemoveCharacter_Set(-2, 0, randum, player, start_time, count); break;
		}
	}
}

int detect(int x, int y, int randum)

{

	int x1 = 0;
	int y1 = 0;

	COORD cur = getCursor();

	/* �̷γ������� ��ġ���*/

	x1 = cur.X + x;
	y1 = cur.Y + y;
	x1 = x1 / 2 - 20;
	y1 = y1 - 5;

	if (((x1 < 0 && x1 >= MAZE_BOARD_WIDTH) || (y1 < 0 && y1 >= MAZE_BOARD_HEIGHT)))  // �̷ι����� ����������
	{
		return 1;
	}

	if (maze[randum][y1][x1] == '1')  //���� ������ �������� �ʵ���
		return 1;

	else if (maze[randum][y1][x1] == 'Q')
		return 2;

	else if (maze[randum][y1][x1] == 'x')   //�̼� ����
		return -1;

	else
		return 0;        //�̷� �ȿ��� ���� ������ �ʰ� �������� ��

}

bool RemoveCharacter_Set(int x, int y, int randum, PLAYER * player, double start_time, int count)
{
	int question_count = 6;
	int answer;
	int num = rand() % question_count;


	int value = detect(x, y, randum);


	COORD NowCur = getCursor();

	if (value == 0)
	{
		COORD cur = getCursor();

		printf("  ");

		setCursor(cur.X + x, cur.Y + y);

		return true;

	}

	else if (value == -1)
	{
		End_Time(player, start_time, count);
		setCursor(0, POINT_Y);

		system("pause");
		return false;
	}

	else if (value == 2)
	{
		Question(num);
		answer = Answer(num);
		Remover(0, POINT_Y, 2);

		if (answer == 1)
		{
			setCursor(NowCur.X, NowCur.Y);
			printf("  ");

			setCursor(NowCur.X + x, NowCur.Y + y);
		}
		else if (answer == 0)
		{
			setCursor(NowCur.X, NowCur.Y);
		}

		return true;
	}

	else return true;
}
