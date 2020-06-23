/******************************************
*Student name: Agai Maor
*Student ID:305544546
*Submit Info:Agaimao
*Exercise name: ex5
******************************************/

#include "Mission4.h"
#include <stdio.h>
void loadBoard(char mat[][MAX_ROWS_COLLOMNS], int rows, int cols);
void runGame(int n, int m, long c, char board[][MAX_ROWS_COLLOMNS]);
void print(int n, int m, int board[][MAX_ROWS_COLLOMNS]);
void extender(int table[][MAX_ROWS_COLLOMNS], int extended[][MAX_ROWS_COLLOMNS + 2], int rows, int columns);
void invertToBinary(int rows, int columns, int binaryTable[][MAX_ROWS_COLLOMNS], char board[][MAX_ROWS_COLLOMNS]);
/************************************************************************
Fill comment
*************************************************************************/
void mission4()
{
	int n, m;
	long c;
	char board[MAX_ROWS_COLLOMNS][MAX_ROWS_COLLOMNS];
	printf("Please enter the number of rows (n):\n");
	scanf("%d", &n);
	if ((n < MIN_ROW_COLUMN) || (n > MAX_ROWS_COLLOMNS))
		return;
	printf("Please enter the number of columns (m):\n");
	scanf("%d", &m);
	if ((m < MIN_ROW_COLUMN) || (m > MAX_ROWS_COLLOMNS))
		return;
	printf("Please enter the number of iterations (c):\n");
	scanf("%ld", &c);
	if ((c < 1) || (c > MAX_ITERATIONS))
		return;
	printf("Please enter the board:\n");
	//validating inputs
	
	loadBoard(board, n, m);		// Reading the Board
	runGame(n, m, c, board);

}

/************************************************************************
* function name: runGame *
* The Input:  grid size,number of iteratins and the grid*
* The output: the grid after c generations *
* The Function operation: *
*************************************************************************/
void runGame(int n, int m, long c, char board[][MAX_ROWS_COLLOMNS])
{
	int binaryTable[MAX_ROWS_COLLOMNS][MAX_ROWS_COLLOMNS], i, j, k;
	int extendedTable[MAX_ROWS_COLLOMNS + 2][MAX_ROWS_COLLOMNS + 2];
	//inverting the char grid to binary grid
	invertToBinary(n, m, binaryTable, board);

	for (k = 0; k < c; k++)
	{
		//checking if the state of the matrix is all cells dead
		if (isAllDead(n, m, binaryTable) == 1)
		{
			printf("The board after %d iterations is:\n", k);
			print(n, m, binaryTable);
			return;
		}
		//creating an extended grid
		extender(binaryTable, extendedTable, n, m);
		//updating the next generation
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				binaryTable[i][j] = futureCell(extendedTable, i + 1, j + 1);
			}
		}
	}
	printf("The board after %d iterations is:\n", c);
	print(n, m, binaryTable);

}
/************************************************************************
* function name: print *
* The Input:size of grid *
* The output: prints the grid *
* The Function operation: printing each cell of the grid *
*************************************************************************/
void print(int n, int m, int board[][MAX_ROWS_COLLOMNS])
{
	int i, k;
	for (i = 0; i < n; i++) {
		for (k = 0; k < m; k++) {
			if (board[i][k] == 0)
				printf("-");
			else
				printf("*");
		}
		printf("\n");
	}
}
/************************************************************************
* function name: loadBoard *
* The Input:size of grid and the grid itself *
* The output: getting the grids values from user*
* The Function operation: using scanf func to get grid from user*
*************************************************************************/
void loadBoard(char mat[][MAX_ROWS_COLLOMNS], int rows, int cols)
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
/************************************************************************
* function name: isAllDead *
* The Input: the grid *
* The output:  returns a value if represents if all the grids cells are dead*
* The Function operation: going through each cell and checks if its dead *
*************************************************************************/
int isAllDead(int n, int m, int board[][MAX_ROWS_COLLOMNS])
{
	int i, k;
	for (i = 0; i < n; i++) {
		for (k = 0; k < m; k++) {
			if (board[i][k] != 0)
				//not all cells in matrix are dead
				return 0;
		}


	}
	//all cells in matrix are dead
	return 1;
}
/************************************************************************
* function name: invertToBinary *
* The Input:the gread and its size *
* The output: inverts a char grid to an int of binary numbers *
* The Function operation: going through each cell and creating a new table accordingly*
*************************************************************************/
void invertToBinary(int rows, int columns, int binaryTable[][MAX_ROWS_COLLOMNS], char board[][MAX_ROWS_COLLOMNS])
{

	int i, k;

	for (i = 0; i < rows; i++) {

		for (k = 0; k < columns; k++)
		{
			if (board[i][k] == '-')
				binaryTable[i][k] = 0;
			if (board[i][k] == '*')
				binaryTable[i][k] = 1;
		}

	}

}
/************************************************************************
* function name: extender *
* The Input: the n*m grid *
* The output: an extended grid for the torus calculation*
* The Function operation: extending the grid following the torus behavior *
*************************************************************************/
void extender(int table[][MAX_ROWS_COLLOMNS], int extended[][MAX_ROWS_COLLOMNS + 2], int rows, int columns)
{
	int i, k;
	char dummy;
	//managing the inner cells
	for (i = 0; i < rows; i++) {

		for (k = 0; k < columns; k++)
		{
			extended[i + 1][k + 1] = table[i][k];
		}

	}
	//managing the left and right columns
	for (i = 0; i < rows; i++) {

		extended[i + 1][columns + 1] = table[i][0];
		extended[i + 1][0] = table[i][columns - 1];

	}
	//managing the upper and bottom lines
	for (i = 0; i < columns; i++)
	{
		extended[rows + 1][i + 1] = table[0][i];
		extended[0][i + 1] = table[rows - 1][i];
	}
	//managing the corners
	extended[rows + 1][columns + 1] = table[0][0];
	extended[rows + 1][0] = table[0][columns - 1];
	extended[0][columns + 1] = table[rows - 1][0];
	extended[0][0] = table[rows - 1][columns - 1];
}
/************************************************************************
* function name: futureCell *
* The Input: a grid and a certain position *
* The output: the future of the cell (dead/alive) depands on its current neighbors*
* The Function operation:  sums the neighbors value and decided what will be the cell destiny*
*************************************************************************/
int futureCell(int extendedTable[][MAX_ROWS_COLLOMNS + 2], int rowPos, int colPos)
{
	int neighboreSum = 0;
	//calculating how many living cells are around the required cell
	neighboreSum = extendedTable[rowPos - 1][colPos - 1] + extendedTable[rowPos - 1][colPos] + extendedTable[rowPos - 1][colPos + 1] +
		extendedTable[rowPos][colPos - 1] + extendedTable[rowPos][colPos + 1] +
		extendedTable[rowPos + 1][colPos - 1] + extendedTable[rowPos + 1][colPos] + extendedTable[rowPos + 1][colPos + 1];
	//deciding what will be the result for the cell in the next gen according to the game laws
	if (extendedTable[rowPos][colPos] == 1)
	{
		if (neighboreSum < 2)
			return 0;
		if ((neighboreSum == 2) || (neighboreSum == 3))
			return 1;
		if (neighboreSum > 3)
			return 0;
	}
	if (extendedTable[rowPos][colPos] == 0)
		if (neighboreSum == 3)
			return 1;
		else
			return 0;

}