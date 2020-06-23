/******************************************
*Student name: Agai Maor
*Student ID:--
*Submit Info:Agaimao
*Exercise name: ex5
******************************************/
#include <stdio.h> 
#include "Mission1.h"

void mission1()
{
	int n, i,k, count = 0;
	char source[STRING_MAX_LENGTH], target[STRING_MAX_LENGTH];

	printf("Please enter the amount of pairs:\n");
	// Input the n
	scanf("%d", &n);
	//validation of n
	if ((n<1) || (n>MAX_NUMBER_OF_STRINGS))
	{
		return;
	}
	// getting the strings
	for (i = 0; i < n; i++)
	{
		printf("Please enter the first string of pair %d:\n", i + 1);
		scanf("%s", target);
		if (sizeString1(target) == -1)
			return;
		printf("Please enter the second string pair %d:\n", i + 1);
		scanf("%s", source);
		if (sizeString1(source) == -1)
			return;
		
		count += isSemiSimilar(target, source);
	}
	printf("The amount of Semi-Similar strings is %d\n", count);
}

/************************************************************************
* function name: isSemiSimilar 											*
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function returns 1 or 0								*
* The Function operation: The function checks if target is 				*
*						   semi-similar to source 						*
*************************************************************************/
int isSemiSimilar(char target[], char source[])
{
	int n = 0, i, j;
	//finding the size of the source string
	while (1)
	{
		if (source[n] == '\0')
			break;
		else
			n++;
	}
	//checkin if the strings are in the same length
	if (target[n] != '\0')
	{
		return 0;
	}
	//checking if the strings are semi-similar
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <n; j++)
		{
			if (source[i] == target[j])
			{
				target[j] = '0';
				break;
			}
		}
	}
	for (i = 0; i < n + 1; i++)
	{
		if (target[i] != '0')
			if (i == n)
				return 1;
			else
				return 0;
	}

}
/************************************************************************
* function name: sizeString 											*
* The Input: a string of chars                                          *
* The output: 	the length of the string							    *
* The Function operation: 	the function counts the chars in the string *
*************************************************************************/
int sizeString1(char string[])
{
	int n = 0;
	while (1)
	{
		if (string[n] == '\0')
			break;
		if ((string[n] < 'a') || (string[n] > 'z'))
			return -1;
		else
			n++;
	}
	return n;
}
