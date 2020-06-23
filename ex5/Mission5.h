/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/ 

#ifndef _MISSION5_H_
#define _MISSION5_H_
#define MAX_ROW_COLUMN_FIVE 25
#define MIN_ROW_COLUMN_FIVE 1
int getMinLength(char mat[][MAX_ROW_COLUMN_FIVE], int startX, int startY, int goalX, int goalY, int n);
void loadCastleBoard(char mat[][MAX_ROW_COLUMN_FIVE], int rows, int cols);
int getMinHelper(char mat[][MAX_ROW_COLUMN_FIVE], int steps[], int counter, int startX, int startY, int goalX, int goalY, int n);
void mission5();
#endif