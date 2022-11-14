#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Function.h"



/* �÷��̾� �Լ� */


int GetPlayer(PLAYER *player, int i)
{

	setCursor(6, 5);
	puts("  �÷��̾� ����\n\n");
	printf("   ����� �̸���? ");
	gets_s((player + i)->name, sizeof((player + i)->name));

	printf("   ����� ���̴�? ");
	scanf("%d", &(player + i)->age);
	getchar();

	printf("   ����� ������? ");
	gets_s((player + i)->major, sizeof((player + i)->major));

	printf("   ����� �й���? ");
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
		printf("�Էµ� ���� ������ ���� \n");
		return;
	}

	int s;

	while (true)
	{

		printf("����Է�: (���� 0) : ");
		scanf("%d%*c", &s);

		if (s == 0)
			return;
		else if (s < 0 || s > num)
		{
			printf("�������� �ʴ� ��� \n");
			continue;
		}

		for (int i = 0;i < num;i++)
		{
			if (s == (player + i)->rank)
				printf("\n�̸�: %s\n���� : %d��\n�а� : %s\n�й� : %.0lf\n�÷��� ��� : %.2f��\n��� : %d��\n\n", (player + i)->name, (player + i)->age,
				(player + i)->major, (player + i)->grade_num, (player + i)->score, (player + i)->rank);
		}
	}
}

void Store_Player(PLAYER * player, int count)
{
	FILE * fp;                                           
	fp = fopen("�÷��̾� ���.txt", "at");

	for (int i = 0;i < count;i++)

	{
		fprintf(fp, "�̸�: %s\n����: %d��\n�а�: %s\n�й�: %.0lf\n�÷��� ���: %.2f��\n���: %d��\n\n", (player + i)->name, (player + i)->age,
			(player + i)->major, (player + i)->grade_num, (player + i)->score, (player + i)->rank);
	}

	fclose(fp);
}