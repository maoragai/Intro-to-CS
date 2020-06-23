/******************************************
*Student name: Agai Maor
*Student ID:305544546
*Submit Info:Agaimao
*Exercise name: ex5
******************************************/

#include "Mission5.h"
#include <stdio.h>
/************************************************************************
Fill comment
*************************************************************************/

int getMinLength(char mat[][MAX_ROW_COLUMN_FIVE], int startX, int startY, int goalX, int goalY, int n);
void loadCastleBoard(char mat[][MAX_ROW_COLUMN_FIVE], int rows, int cols);
int getMinHelper(char mat[][MAX_ROW_COLUMN_FIVE], int steps[], int counter, int startX, int startY, int goalX, int goalY, int n);
void mission5()
{
	int n;
	char board[MAX_ROW_COLUMN_FIVE][MAX_ROW_COLUMN_FIVE];

	int startX, startY, goalX, goalY, result;

	printf("Please enter the number of rows and columns (n):\n");
	scanf("%d", &n);
	if ((n < MIN_ROW_COLUMN_FIVE) || (n > MAX_ROW_COLUMN_FIVE))
		return;
	printf("Please enter the X of the starting position:\n");
	scanf("%d", &startX);
	if ((startX < MIN_ROW_COLUMN_FIVE-1) || (startX > n-1))
		return;
	printf("Please enter the Y of the starting position:\n");
	scanf("%d", &startY);
	if ((startY < MIN_ROW_COLUMN_FIVE-1) || (startY> n-1))
		return;
	printf("Please enter the X of the goal position:\n");
	scanf("%d", &goalX);
	if ((goalX < MIN_ROW_COLUMN_FIVE-1) || (goalX > n-1))
		return;
	printf("Please enter the Y of the goal position:\n");
	scanf("%d", &goalY);
	if ((goalY< MIN_ROW_COLUMN_FIVE-1) || (goalY > n-1))
		return;
	printf("Please enter the grid:\n");
	
	loadCastleBoard(board, n, n);		// Reading the Board
	// Getting the Minimum Value
	result = getMinLength(board, startX, startY, goalX, goalY, n);
	if (result != -1)
	{
		printf("The minimum number of steps is %d\n", result);
	}
	else
	{
		printf("No path was found from (%d,%d) to (%d,%d)\n", startX, startY, goalX, goalY);
	}
}

/************************************************************************
* function name: getMinLength *
* The Input: the games grid ,a counter,current position, size of grid,goal position,the steps array *
* The output: returns the amount of steps required to get to the goal *
* The Function operation: calls and handles the recursive function getMinHelper *
*************************************************************************/
int getMinLength(char mat[][MAX_ROW_COLUMN_FIVE], int startX, int startY, int goalX, int goalY, int n)
{
	int steps[2] = { -1,0 };
	//initial recursion call
	getMinHelper(mat, steps, 0, startX, startY, goalX, goalY, n);
	//returnes the amount of steps 
	return steps[0];

}
/************************************************************************
* function name: getMinHelper *
* The Input: *
* The output: the amount of steps required to get to the goal *
* The Function operation: recursion that finds the shortes way to get to the goal*
*************************************************************************/
int getMinHelper(char mat[][MAX_ROW_COLUMN_FIVE], int steps[], int counter, int startX, int startY, int goalX, int goalY, int n)
{	//check for blocked path
	if (mat[startX][startY] == 'X')
	{
		//blocked by an X
		return;
	}
	//handeling a solution
	if ((startX == goalX) && (startY == goalY))
	{
		//reached destination
		if (steps[0] == -1)
		{// there was no prior solution therefore entering the number of steps
			steps[0] = counter;
			return;
		}
		if ((steps[0] != -1) && (counter < steps[0]))
		{//there was a prior solution but the current solution has fewer steps
			steps[0] = counter;
			return;
		}
		else
		{
			return;
		}

	}
	//marking the current position so the recurse wont come back to it
	mat[startX][startY] = 'X';
	//going right
	if (startY < n - 1) {
		getMinHelper(mat, steps, counter + 1, startX, startY + 1, goalX, goalY, n);

	}
	//going bottom
	if (startX < n - 1) {
		getMinHelper(mat, steps, counter + 1, startX + 1, startY, goalX, goalY, n);

	}
	//going up
	if (startX>0)
		getMinHelper(mat, steps, counter + 1, startX - 1, startY, goalX, goalY, n);
	//going left
	if (startY>0)
		getMinHelper(mat, steps, counter + 1, startX, startY - 1, goalX, goalY, n);
}

/************************************************************************
* function name: loadCastleBoard *
* The Input: two dimentional array mat,number of rows and columns*
* The output: two dimentional array*
* The Function operation:gets the grid from the user *
*************************************************************************/
void loadCastleBoard(char mat[][MAX_ROW_COLUMN_FIVE], int rows, int cols)
{

	// The Function reads from the IO and loads to the array
	int i, k;
	char dummy;
	for (i = 0; i < rows; i++) {
		scanf("%c", &dummy);
		for (k = 0; k < cols; k++)
		{

			scanf("%c", &(mat[i][k]));
		}

	}

}
