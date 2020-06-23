/******************************************
*Student name: Agai Maor
*Student ID:305544546
*Submit Info:Agaimao
*Exercise name: ex5
******************************************/

#include "Mission2.h"
#include <stdio.h>

/************************************************************************
* function name: SweetCookies *
* The Input: the array of cookies the array length and sweetness level*
* The output:returns the amount of operations needed to acceed the level of seetness *
* The Function operation: *
*************************************************************************/
int SweetCookies(int cookies[], int n, int K)
{

	int currentSweetness = 0, i, j, counter = 0, swtch, miniPos, mini = MAX_LEVEL_SWEETNESS;
	
	if (stringValidation(cookies, n, K) == 1)
		return 0;
	while (stringValidation(cookies, n, K) != 1)
	{
		//sorting the array
		for (j = n; j > 0; j--)
		{
			for (i = 0; i < j - 1; i++)
			{
				if (cookies[i] > cookies[i + 1])
				{
					swtch = cookies[i];
					cookies[i] = cookies[i + 1];
					cookies[i + 1] = swtch;
				}
			}
		}
		//calculating sweetness level
		currentSweetness = 1 * cookies[0] + 2 * cookies[1];
		//insering new sweetnes level into array
		cookies[0] = currentSweetness;
		//updating the array
		for (i = 1; i < n; i++)
		{
			cookies[i] = cookies[i + 1];

		}
		counter++;
		n--;

	}
	return counter;
}
/************************************************************************
* function name: stringValidation *
* The Input:a tring of numbers, the size of the string and level of sweetness *
* The output:returns a value if all the numbers within the array aer above sweetnes level *
* The Function operation:  checks every number in array*
*************************************************************************/
int stringValidation(int string[], int n, int sweet)
{
	int i;
	for (i = 0; i < n; i++)
	{//theres a number smaller than sweetness level
		if (string[i] < sweet)
			return 0;
	}
	// all the array is above sweetnes level
	return 1;
}

/************************************************************************
Fill comment
*************************************************************************/
void mission2()
{
	int n, sweet;
	int cookies[MAX_NUMBER_COOCKIES];
	int i;
	int result;

	printf("Please enter the amount of cookies:\n");
	scanf("%d", &n);
	if ((n < 1) || (n > MAX_NUMBER_COOCKIES))
		return;
	printf("Please enter the minimum required sweetness:\n");
	scanf("%d", &sweet);
	if ((sweet < 0) || (sweet> MAX_LEVEL_SWEETNESS) )
		return;

	for (i = 0; i < n; i++)
	{
		printf("Please enter cookie number %d:\n", i + 1);
		scanf("%d", &cookies[i]);
		if ((cookies[i] < 0) || (cookies[i] > MAX_COOCKIE_SWEETNESS))
			return;
	}

	result = SweetCookies(cookies, n, sweet);
	printf("The number of operations that are needed is %d\n", result);
}