

/* 맵 시작 위치 및 움직임 아스키 코드*/


#ifndef __POINT_H_
#define __POINT_H_

#define POINT_X 40            // 보드시작좌표x
#define POINT_Y 5             // 보드시작좌표y

#define LEFT 75 
#define RIGHT 77
#define UP 72
#define DOWN 80

#endif


/* 맵 */


#ifndef __MAP_H_
#define __MAP_H_

#define Map_Count 5               // 5개의 맵
#define MAZE_BOARD_HEIGHT 20      // 세로
#define MAZE_BOARD_WIDTH 20       // 가로

int maze[Map_Count][MAZE_BOARD_HEIGHT][MAZE_BOARD_WIDTH];

#endif