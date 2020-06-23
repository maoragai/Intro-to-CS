/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/ 

#ifndef _MISSION4_H_
#define _MISSION4_H_
#define MAX_ROWS_COLLOMNS 25
#define MIN_ROW_COLUMN 3
#define MAX_ITERATIONS 100000
void mission4();
void loadBoard(char mat[][MAX_ROWS_COLLOMNS], int rows, int cols);
void runGame(int n, int m, long c, char board[][MAX_ROWS_COLLOMNS]);
void print(int n, int m, int board[][MAX_ROWS_COLLOMNS]);
void extender(int table[][MAX_ROWS_COLLOMNS], int extended[][MAX_ROWS_COLLOMNS + 2], int rows, int columns);
void invertToBinary(int rows, int columns, int binaryTable[][MAX_ROWS_COLLOMNS], char board[][MAX_ROWS_COLLOMNS]);
#endif