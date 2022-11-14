#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Function.h"



/* 플레이어 함수 */


int GetPlayer(PLAYER *player, int i)
{

	setCursor(6, 5);
	puts("  플레이어 정보\n\n");
	printf("   당신의 이름은? ");
	gets_s((player + i)->name, sizeof((player + i)->name));

	printf("   당신의 나이는? ");
	scanf("%d", &(player + i)->age);
	getchar();

	printf("   당신의 전공은? ");
	gets_s((player + i)->major, sizeof((player + i)->major));

	printf("   당신의 학번은? ");
	scanf("%lf", &(player + i)->grade_num);

	return i + 1;
}

void RANK(PLAYER *player, int num)
{
	for (int i = 0;i < num;i++)
	{
		(player + i)->rank = 1;

		for (int j = 0;j < num;j++)
		{
			if ((player + i)->score > (player + j)->score)
				(player + i)->rank++;
		}
	}
}

void SEARCH(PLAYER * player, int num)
{
	setCursor(6, 5);

	if (num == 0)
	{
		printf("입력된 유저 정보가 없음 \n");
		return;
	}

	int s;

	while (true)
	{

		printf("등수입력: (종료 0) : ");
		scanf("%d%*c", &s);

		if (s == 0)
			return;
		else if (s < 0 || s > num)
		{
			printf("존재하지 않는 등수 \n");
			continue;
		}

		for (int i = 0;i < num;i++)
		{
			if (s == (player + i)->rank)
				printf("\n이름: %s\n나이 : %d세\n학과 : %s\n학번 : %.0lf\n플레이 기록 : %.2f초\n등수 : %d등\n\n", (player + i)->name, (player + i)->age,
				(player + i)->major, (player + i)->grade_num, (player + i)->score, (player + i)->rank);
		}
	}
}

void Store_Player(PLAYER * player, int count)
{
	FILE * fp;                                           
	fp = fopen("플레이어 기록.txt", "at");

	for (int i = 0;i < count;i++)

	{
		fprintf(fp, "이름: %s\n나이: %d세\n학과: %s\n학번: %.0lf\n플레이 기록: %.2f초\n등수: %d등\n\n", (player + i)->name, (player + i)->age,
			(player + i)->major, (player + i)->grade_num, (player + i)->score, (player + i)->rank);
	}

	fclose(fp);
}