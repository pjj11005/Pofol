

#ifndef __FUNCTION_H_              
#define __FUNCTION_H_


/* �÷��̾� ���� */


typedef struct
{

	int age, rank;
	double grade_num, score;
	char name[12];
	char major[24];


} PLAYER;


/* ���� �˰��� �Լ� */


void character_static(int, PLAYER *, int);                       // ĳ���� �����̱�
int detect(int, int, int);                                       // ĳ���� ������ ����
bool RemoveCharacter_Set(int, int, int, PLAYER *, double, int);  // ������ ĳ���� �����


/* �� �Լ� */


 int RandumNum(void);                      // ���� �� ����
 void Main_Start(void);                    // �� �ε� ȭ�� ���
 void showBoard(int);                      // �̷��� ���


 /* �÷��̾� �Լ� */


 int GetPlayer(PLAYER *, int);             // �÷��̾� ���� �Է�
 void RANK(PLAYER *, int);                 // ��ũ ����
 void SEARCH(PLAYER *, int);               // ��ũ �˻�
 void Store_Player(PLAYER *, int);         // �÷��̾� ���� txt�� ����


/* ���� �Լ� */


 void Question(int);                       // ���� ���
 int Answer(int);                          // ���� Ȯ��


/* �޴� �Լ� */


 int Menu(void);                           // �޴�â ���
 void Team_Player(void);                   // ���� ���� ���

/* Ŀ�� �Լ� */


 void removeCursor(void);                  // Ŀ�� ������ �����
 COORD getCursor(void);                    // �ܼ� ��ġ �ޱ�
 void setCursor(int, int);                 // �ܼ� ��ġ ����


/* ĳ���� �Լ� */


 void showCharacter(void);                                // ĳ���� ���


/* �ð� �Լ� */


 double Start_Time(void);                  // ���� �ð� ����
 void End_Time(PLAYER *, double, int);     // ���� �ð� ����


/* ��Ÿ �Լ� */


 void Remover(int, int, int);              // ���찳
 void WinFunc(int);                        // �ܼ� ���� �� �� ����
 void TextColor(int);                      // ���� �� ����

#endif