/******************************************
*Student name: Maor Agai
*Student ID:--
*Exercise name: ex2
******************************************/

#include <stdio.h>
#define MAX_BASE 10
#define MIN_BASE 2
/*main function
gets an integer input from the user (a number between 1-4)
and acts accordingly
in case of 1- Full adder
		   2- 
		   3- 
		   4-
		   */
int main()
{
	//varaiable used to get the user's coice
	int userOptionChoice = 0;
	//mission one variables
	int base,number1,number2;

	
	//mission two variables
	
	//mission three variables

	//mission four variables

	//asking user to enter his choice
	printf("Please choose an option: \n");
	scanf("%d", &userOptionChoice);
	//following users choice with a switch,case,break structure
	switch (userOptionChoice)
	{
	case 1://Mission one-Full Adder
		printf("Please enter the base of the problem:\n");
		scanf("%d", &base);
		printf("Please enter the first number in base %d: \n",base);
		scanf("%d", &number1);
		printf("Please enter the second number in base %d: \n", base);
		scanf("%d", &number2);
		//checking if the base is in the valid range
		if(base>MAX_

	case 2:

	case 3:

	case 4:
		break;
	}
}
