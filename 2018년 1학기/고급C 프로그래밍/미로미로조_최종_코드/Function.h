

#ifndef __FUNCTION_H_              
#define __FUNCTION_H_


/* 플레이어 정보 */


typedef struct
{

	int age, rank;
	double grade_num, score;
	char name[12];
	char major[24];


} PLAYER;


/* 메인 알고리즘 함수 */


void character_static(int, PLAYER *, int);                       // 캐릭터 움직이기
int detect(int, int, int);                                       // 캐릭터 움직임 조건
bool RemoveCharacter_Set(int, int, int, PLAYER *, double, int);  // 움직인 캐릭터 지우기


/* 맵 함수 */


 int RandumNum(void);                      // 랜덤 맵 선택
 void Main_Start(void);                    // 맵 로딩 화면 출력
 void showBoard(int);                      // 미로판 출력


 /* 플레이어 함수 */


 int GetPlayer(PLAYER *, int);             // 플레이어 정보 입력
 void RANK(PLAYER *, int);                 // 랭크 설정
 void SEARCH(PLAYER *, int);               // 랭크 검색
 void Store_Player(PLAYER *, int);         // 플레이어 정보 txt로 저장


/* 문제 함수 */


 void Question(int);                       // 문제 출력
 int Answer(int);                          // 정답 확인


/* 메뉴 함수 */


 int Menu(void);                           // 메뉴창 출력
 void Team_Player(void);                   // 팀원 정보 출력

/* 커서 함수 */


 void removeCursor(void);                  // 커서 깜박이 지우기
 COORD getCursor(void);                    // 콘솔 위치 받기
 void setCursor(int, int);                 // 콘솔 위치 지정


/* 캐릭터 함수 */


 void showCharacter(void);                                // 캐릭터 출력


/* 시간 함수 */


 double Start_Time(void);                  // 시작 시간 측정
 void End_Time(PLAYER *, double, int);     // 끝난 시간 측정


/* 기타 함수 */


 void Remover(int, int, int);              // 지우개
 void WinFunc(int);                        // 콘솔 제목 및 색 조정
 void TextColor(int);                      // 글자 색 조정

#endif