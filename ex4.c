/******************************************
*Student name: Maor Agai
*Student ID:305544546
*Exercise name: ex4
******************************************/
#include <stdio.h>
//mission one const
#define N_MAX 1000
#define N_MIN 1
#define AB_MAX 1000000000
#define AB_MIN 1
//mission two const
#define MISSION_2_MAX 300
#define MISSION_2_MIN 0

//mission three const
#define MISSION_3_MIN 1
#define MISSION_3_MAX 100
//mission four const
#define MISSION_4_MIN 1
#define MISSION_4_MAX 30
#define PAPER_PRINT "Paper"
#define LIZARD_PRINT "Lizard"
#define SPOCK_PRINT "Spock"
#define SCISSORS_PRINT "Scissors"
#define ROCK_PRINT "Rock"
#define MAX_ROUNDS 30
#define MIN_ROUNDS 1

/*main function
gets an integer input from the user (a number between 1-4)
and acts accordingly
*/

enum { Rock = 0, Paper = 1, Scissors = 2, Lizard = 3, Spock = 4 };
//list of functions
int getsWinner(int aliceShape, int bobShape);
int xoring(unsigned long x, unsigned long a);
int maxDivider(int num, int div);
int pathSearch(int n,int c);
int findDivsion(int n,int c);
int getAlice(int bobsShape);
int getBob(int lastResult);
int isContain(int number1,int number2);
void printShape(int shape);

int main()
{
	//varaiable used to get the user's choice
	int userOptionChoice = 0;
	//mission one variables
	int numberOfPairs=0,number1=0,number2=0,counter,i;
	//mission two variables
	int numberToDivide;
	//mission three variables
	unsigned long numberToCheck;
	int xoredCounter;
	//mission four variables
	int aliceWinsCounter, bobWinsCounter, numberOfRounds;
	int alice,bob,tieCounter, lastResult;
//**********************80 chars frame*****************************************
	while(1)
	{	
		//asking user to enter his choice
		printf("Please enter the mission number: \n");
		scanf("%d", &userOptionChoice);
		//following users choice with a switch,case,break structure
		switch (userOptionChoice)
		{
		case 1://checks if a number contains another number
			counter = 0;
			number1 = 0;
			number2 = 0;
			numberOfPairs = 0;
			i = 0;
			printf("Please enter the number of pairs:\n");
			scanf("%d", &numberOfPairs);
			//a loop asking the user for the pairs and then checks them 
			if((numberOfPairs<=N_MAX)&&(numberOfPairs>=N_MIN))
			for ( i = 1; i <=numberOfPairs; i++)
			{
				printf("Please enter the larger number of pair %d (a):\n",i);
				scanf("%d", &number1);
				printf("Please enter the smaller number of pair %d (b):\n",i);
				scanf("%d", &number2);
				if ((number1 <= AB_MAX) && (number1 >= AB_MIN) &&
					(number2 <= AB_MAX) && (number2 >= AB_MIN)) {
					if (isContain(number1, number2) == 1)
						counter++;
				}
				else
					break;
			}
			printf("The number of pairs satisfying the condition is: %d\n",counter);//////////////////////////
			break;
		case 2://divide path search
				printf("Please enter the number:\n");
				scanf("%d", &numberToDivide);				
				if ((numberToDivide < MISSION_2_MIN) ||
					(numberToDivide > MISSION_2_MAX))
					break;
			   printf("The sequence of numbers produced by the actions is:\n");
				counter = findDivsion(numberToDivide,0);
				break;
		case 3://xor operation
			printf("Please enter the number:\n");
			scanf("%d", &numberToCheck);
			if ((numberToCheck < MISSION_3_MIN) ||
				(numberToCheck > MISSION_3_MAX))
				break;
			printf("The numbers are:\n");
			xoredCounter=xoring(numberToCheck, 1);
			printf("A total of %d numbers\n", xoredCounter);					
			break;
		case 4://mission 4
			bobWinsCounter = 0;
			tieCounter = 0;
			aliceWinsCounter=0;
			i = 0;
			//lastResult = 0;
			printf("Please enter the shape Alice chose:\n");
			scanf("%d", &alice);
			printf("Please enter the shape Bob chose:\n");
			scanf("%d", &bob);
			printf("Please enter the number of rounds:\n");
			scanf("%d", &numberOfRounds);
			if ((numberOfRounds < MISSION_4_MIN) ||
				(numberOfRounds > MISSION_4_MAX))
				break;
			for ( i = 1; i <= numberOfRounds; i++)
			{//bob wins
				if ((lastResult=getsWinner(alice, bob)) == 0) 
					{
						printShape(alice);
						printf(" < ");
						printShape(bob);
						printf("\n");
						bobWinsCounter++;
					}//alice wins
				else if ((lastResult=getsWinner(alice, bob)) == 1)
				{
					printShape(alice);
					printf(" > ");
					printShape(bob);
					printf("\n");
					aliceWinsCounter++;
				}//tie
				else if ((lastResult=getsWinner(alice, bob)) == 2)
				{
					printShape(alice);
					printf(" = ");
					printShape(bob);
					printf("\n");
					tieCounter++;
				}
				//entering new shapes to the players
				if (lastResult == 1)
					alice = alice;
				else if (lastResult!=1)
					alice = getAlice(bob);
				if (bob == 4)
					bob = getBob(lastResult);
				else if (bob!=4)
					bob = getBob(5);
			}
			//print results of game
			if (aliceWinsCounter>bobWinsCounter)
			{
				printf("Alice wins, by winning %d game(s) and tying %d game(s)\n", aliceWinsCounter, tieCounter);
			}
			else if (aliceWinsCounter<bobWinsCounter)
			{
				printf("Bob wins, by winning %d game(s) and tying %d game(s)\n", bobWinsCounter, tieCounter);
			}
			else if (aliceWinsCounter == bobWinsCounter)
			{
				printf("Alice and Bob tie, each winning %d game(s) and tying %d game(s)\n", bobWinsCounter, tieCounter);
			}
		break;
		default:
		return 0;
		break;
		}
	}
		
}
//**********************80 chars frame*****************************************	
/************************************************************************
* function name: isContain *
* The Input: two integers number1,number2 *
* The output: an int number in the values of 1 or 0 *
* The Function operation: checks if number1 contains number2 in it *
*************************************************************************/
int isContain(int number1,int number2)
{
	int sequence=0,initialNumber=number2;
	//a loop that runs till number1 or number2 becomes zero
	while ((number1 != 0) && (number2 != 0))
	{
		//check if substruction of the second number from the first one
		//will zero its last digits (and therefor their equal)
		if ((number1 - number2) % 10 == 0) {
			number1 = number1 / 10;
			number2 = number2 / 10;
			//sequance variable is here to verify that the numbers are
			//consecutive
			if(sequence!=1)
				sequence = 1;
		}
		else if (((number1 - number2) % 10 != 0)|| 
					(number1 % 10 == number2 % 10)) 
		{
			if(sequence!=1)
				number1 = number1 / 10;
			sequence = 0;
			number2 = initialNumber;
		}
		if (number2 == 0)
			return 1;
	}
	return 0;
}
/************************************************************************
* function name: findDivsion *
* The Input: an integer to check  *
* The output: printing the numbers of any step and in the end the 
			  number of steps *
* The Function operation:  *
*************************************************************************/
int findDivsion(int number,int stepsCount)
{
	int pathDecrease, pathDevide, divider;
	//if n is equal to 0 its the end of the tree
	if (number == 0)
	{
		printf("The minimum number of moves is %d\n",stepsCount);
					return;
	}
	//divider gets the larger divider of n from maxdivider func
	divider = maxDivider(number,2);
	//check if the larger divider of n is diffrent from 0
	if (divider != 0)
	{
		//calls pathSearch function so it will see if this way goes faster
		pathDecrease = pathSearch( number-1 ,0);
		// calls the pathSearch func to see if this way goes faster for n 
		pathDevide = pathSearch(divider,0);
		//check what way is fasterand prints the value if it
		if (pathDecrease < pathDevide)
		{
			printf("%d\n",number-1);
			findDivsion(number-1,stepsCount+1);
		}
		else {
			printf("%d\n",divider);
			findDivsion(divider,stepsCount+1);
		}
		return;
	}
	printf("%d\n",number-1);
	findDivsion(number-1,stepsCount+1);
}
/************************************************************************
* function name: maxDivider *
* The Input: an integer we should find a divider for,and an initial divider *
* The output: an integer which is the largest divider of numberToDivide *
* The Function operation: finds the larger divider of a number *
*************************************************************************/
int maxDivider(int numberToDivide,int divider)
{
	int largestDivider;
	//recursion end point
	if (divider == numberToDivide)
		return 0;
	//checks if the divider divide the number without remainder
	if ((numberToDivide%divider)&&(numberToDivide>=divider))
	{
		return maxDivider(numberToDivide,divider+1);
	}
	largestDivider =numberToDivide/divider;

	return largestDivider;
	
}
/************************************************************************
* function name: pathSearch *
* The Input: an integer to check for and integer for counter *
* The output: returns the minimum of steps required to get to 0*
* The Function operation: the function checks by reqursion how many 
							steps are requierd to get to 0 *
*************************************************************************/

int pathSearch(int n,int c) {
	int way1,way1min=n,way2min=n, way2,div;
	div = maxDivider(n,2);
	if (n == 0)
		return c;
	way1 =  pathSearch(div,c+1);
	way2 = pathSearch(n - 1,c+1);
	if (way1 < way1min)
		way1min = way1;
	if (way2 < way2min)
		way2 = way1min;
	if (way1min < way2min)
		return way2min;
	else if (way1min >= way2min)
		return way1min;
}
/************************************************************************
* function name: xoring *
* The Input: two long integer (unsigned) *
* The output: the amount of integer which their xor operation with x is 
			  greater than x*
* The Function operation: a function that checks how many numbers between 
							a and x, are greater than x ,when xored with
							x*
*************************************************************************/
int xoring(unsigned long x, unsigned long a)
{
	unsigned long xor;
	int counter;
	//xoring the numbers
	xor = x^a;
	//recursion end point
	if (x == a)
		return 0;
	// checks if the xor result is larger than x itself
	if (xor > x) {
		printf("%d \n", a);
		counter = 1 + xoring(x, a + 1);
		return counter;
	}
	else if (xor < x) {
		counter =0+  xoring(x, a + 1);
		return counter;
	}	
}

/************************************************************************
* function name: getAlice *
* The Input: an integer represnts bob's shape in the last round *
* The output: an integer represnts the shape for alice's next round *
* The Function operation: the function gets bob's last shape and changes
						   alices shape accordingly*
*************************************************************************/
int getAlice(int bobsShape) 
{
	switch (bobsShape)
	{
		//rock
	case 0:return 1;//paper beats spock
		//paper
	case 1:return 2;
		//scissors
	case 2:return 4;
		//lizard
	case 3:return 0;
		//spock
	case 4:return 3;
	default:
		break;
	}
}
/************************************************************************
* function name: getBob *
* The Input: an integer represents the last match's result *
* The output: returns an integer reprsents the shape for bob 
			  for the next round *
* The Function operation: checks the last round's result and changes 
						  bob's shape accordingly*
*************************************************************************/
int getBob(int lastResult) {
	switch (lastResult)
	{
		//bob won
	case 0:return 0;
		//bob lost
	case 1:return 1;
		//tie
	case 2: return 3;
	default: return 4;
		break;
	}
}
/************************************************************************
* function name: getsWinner *
* The Input: two number represnts the shapes alice and bob holds *
* The output: returns an int represents the score of the round *
* The Function operation: the function checks what is the case of alices
shape and looks for the result for any of bobs shape*
*************************************************************************/
int getsWinner(int aliceShape, int bobShape)
{
	switch (aliceShape)
	{	
		//////////////rock
	case 0: 
			//  paper          spock
		if ((bobShape == 1) || (bobShape == 4))
			return 0;//bob wins
		//          lizard              scissors
		else if ((bobShape == 3) || (bobShape == 2))
			return 1;//bob loses
		else if (bobShape == 0)
			return 2;//tie
	
		//////////////paper
	case 1://  scissors          lizard
		if ((bobShape == 2) || (bobShape == 3))
			return 0;//bob wins
			//          rock              spock
		else if ((bobShape == 0) || (bobShape == 4))
			return 1;//bob loses
		else if (bobShape == 1)
			return 2;//tie

		/////////////////scissors
	case 2:
		//  spock            rock
		if ((bobShape == 4) || (bobShape == 0))
			return 0;//bob wins
		 //         lizard              scissors
		else if ((bobShape == 3) || (bobShape == 1))
			return 1;//bob loses
		else if (bobShape == 2)
			return 2;//tie

		/////////////////lizard
	case 3:
		//  scissors           rock
		if ((bobShape == 2) || (bobShape == 0))
			return 0;//bob wins
		 //          spock              paper
		else if ((bobShape == 4 ) || (bobShape == 1))
			return 1;//bob loses
		else if (bobShape == 3)
			return 2;//tie

		///////////////spock
	case 4:
		//  lizard          paper 
		if ((bobShape == 3) || (bobShape == 1))
			return 0;//bob wins
		 //          scissors              rock
		else if ((bobShape == 2) || (bobShape == 0))
			return 1;//bob loses
		else if (bobShape == 4)
			return 2;//tie
	default:break;
	}
}
/************************************************************************
* function name: printShape *
* The Input: a number represents the shape *
* The output: prints the shape *
* The Function operation: prints the shapes name *
*************************************************************************/
void printShape(int shape)
{
	switch (shape)
	{	//rock
	case 0:printf("%s", ROCK_PRINT); break;
		//paper
	case 1:printf("%s", PAPER_PRINT); break;
		//scissors
	case 2:printf("%s", SCISSORS_PRINT); break;
		//lizard
	case 3:printf("%s",LIZARD_PRINT); break;
		//spock
	case 4:printf("%s", SPOCK_PRINT); break;
	default:
		break;
	}
}