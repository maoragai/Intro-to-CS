/******************************************
*Student name: Maor Agai
*Student ID:305544546
*Exercise name: ex3
******************************************/

#include <stdio.h>
//mission one const
#define MAX_BASE 10
#define MIN_BASE 2
//mission two const
#define MISSION_2_MAX_LIMIT 10000000
//mission three const
#define MISSION_3_MAX_LIMIT 10000
//mission four const
#define MISSION_4_MAX_LIMIT 1073741824


/*main function
gets an integer input from the user (a number between 1-4)
and acts accordingly
*/
int main()
{
	//varaiable used to get the user's choice
	int userOptionChoice = 0;
	//mission one variables
	int base=0, numberOneDec = 0, i, j, numberTwoDec = 0, decimalExpo = 0, baseExpo = 0, var1 = 3, var2 = 0, summaryDec;
	long number1, number2, var, summaryBase = 0,  digitNumber = 0, expoNumber,initializedNumber1,initializedNumber2;
	//mission two variables
	int time = 0, timeCount = 0, value, summary;
	//mission three variables
	int inRangeCounter;
	long  p, q, l, r, initializedP;
	//mission four variables
	int hasLead;//louise-0,richard-1
	int louisenumber, richardnumber;
	long initialValue, expoTwo, numberShifted, userNumber;

	while(1)
	{	
		//asking user to enter his choice
		printf("Please enter the mission number: \n");
		scanf("%d", &userOptionChoice);
		//following users choice with a switch,case,break structure
		switch (userOptionChoice)
			{
				case 1://Mission one-Full Adder
					base = 0;
					number1 = 0;
					number2 = 0;
					numberOneDec = 0;
					numberTwoDec = 0;
					decimalExpo = 0;
					baseExpo = 0;
					var1 = 0;
					var2 = 0;
					summaryBase = 0;
					digitNumber = 0;
					printf("Please enter the base of the problem:\n");
					scanf("%d", &base);
					//checking if the base is in the valid range
					if ((base > MAX_BASE) || (base < MIN_BASE))
					{
						printf("ERROR - The base %d is not between 2 and 10 \n", base);
						break;
					}
					printf("Please enter the first number in base %d: \n", base);
					scanf("%d", &number1);
					printf("Please enter the second number in base %d: \n", base);
					scanf("%d", &number2);
					initializedNumber1 = number1;
					initializedNumber2 = number2;
					
					//converting both numbers to base 10
					for (i = 8; i >= 0; i--)
						{
							decimalExpo = 10;
							baseExpo = base;
							//exponantiarion
							for (j = (i - 1); j > 0; j--) {
								decimalExpo = decimalExpo * 10;
								baseExpo = baseExpo*base;
							}
							//dealing with the case of exponantioation by 0
							if (i == 0) {
								decimalExpo = 1;
								baseExpo = 1;
							}
							//calculating the value in decimal base
							var1 = (number1 / decimalExpo);
							var2 = (number2 / decimalExpo);
							numberOneDec = numberOneDec + ((var1)*baseExpo);
							numberTwoDec = numberTwoDec + ((var2)*baseExpo);
							number1 = number1 - ((number1 / decimalExpo) * decimalExpo);
							number2 = number2 - ((number2 / decimalExpo) * decimalExpo);
						}

					//printf("%d\n%d\n", numberOneDec, numberTwoDec);
					summaryDec = numberOneDec + numberTwoDec;
					for (i = 8; i >= 0; i--) {
						decimalExpo = 10;
						baseExpo = base;
						//exponantiarion
						for (j = (i - 1); j > 0; j--) {
							decimalExpo = decimalExpo * 10;
							baseExpo = baseExpo*base;
						}
						//dealing with the case of exponantioation by 0
						if (i == 0) {
							decimalExpo = 1;
							baseExpo = 1;
						}
						if ((summaryDec / baseExpo) != 0) {
							summaryBase += (summaryDec / baseExpo)*decimalExpo;
							summaryDec = summaryDec%baseExpo;
						}

					}
					//printing the answer in base 
					printf("The result of %li + %li in base %d is %li\n", initializedNumber1,initializedNumber2,base,summaryBase);
					break;

				case 2://strange counter
					var1 = 3;
					timeCount = 0;
					time = 0;
					printf("Please enter the time:\n");
					scanf("%d", &time);
					if ((time<=0)||(time>=MISSION_2_MAX_LIMIT))
					{
						printf("ERROR - The time %d is invalid\n", time);
						break;
					}
					while (timeCount <= time)
					{
						for (i = var1; i > 0; i--)
						{
							timeCount++;
							if (timeCount == time)
							{
								value = i;
								printf("The time in the timer after %d seconds is %d \n", time, i);
								break;
							}
						}
							var1 = var1 * 2;
						
					}break;


				case 3://gee keeper
					inRangeCounter = 0;
					expoNumber = 0;
					summary = 0;
					initializedP = 0;
					//getting the range from the user
					printf("Please enter the lower limit of the range (p):\n");
					scanf("%d", &p);
					printf("Please enter the upper limit of the range (q):\n");
					scanf("%d", &q);
					//validating range is correct and q is larger then p
					if ((p>=q)||(p<0)||(q<0)||(q>MISSION_3_MAX_LIMIT))
					{
						printf("ERROR - The range %li to %li isn't valid\n", p,q);
						break;
					}
					initializedP = p;
					while (p <= q)
					{
						decimalExpo = 1;
						digitNumber = 0;
						//figering what is the numbers of digit in p
						for (i = 6; i >= 0; i--)
						{
							decimalExpo = 1;
							for (j = i - 1; j >= 0; j--)
								{
									decimalExpo = decimalExpo * 10;
									if (i == 0)
										decimalExpo = 1;
								}
								if ((p / decimalExpo) != 0)
									digitNumber++;
						}
						//exponantiating the number in the power of 2
						expoNumber = p*p;
						//split the number into two parts
						digitNumber = 2 * digitNumber;
						//because im stupid this is the only solution i found to split cases if the number of digits is even
						if (digitNumber % 2 == 0)
						{
							digitNumber = digitNumber / 2;
						}//number of digits is odd
						else 
						{
								digitNumber = (digitNumber / 2) + 1;
						}
						//now digitnumber represents the number of digits in L and R
						decimalExpo = 1;
						for (j = digitNumber - 1; j >= 0; j--)
						{
								decimalExpo = decimalExpo * 10;
								//if (j = 0)
									//decimalExpo = 1;
						}
						l = expoNumber / decimalExpo;
						r = expoNumber%decimalExpo;
						//summing the parts
						summary = l + r;
						//check if the sum is equal to p
						if (summary == p)
						{
							if (inRangeCounter == 0)
								printf("The numbers between %li and %li are:\n", initializedP, q);
							inRangeCounter++;
							printf("%d\n", p);
						}
						//increasing p by 1
						p++;
						
					}
					if (inRangeCounter == 0)
						printf("NO NUMBERS BETWEEN %li AND %li\n", initializedP, q);
					
					break;

	case 4://mission 4
		initialValue = 0;
		expoTwo = 0;
			//getting the initial number from the user 
			printf("Please enter the initial value for the game:\n");
			scanf("%d", &initialValue);
			//verifing initial value is within the valid range
			hasLead = 0;
			louisenumber = initialValue;
			userNumber = initialValue;

			while (initialValue > 1)
			{	//printing the 
				if (hasLead == 1)
					printf("Richard: %d\n", initialValue);
				else
					printf("Louise: %d\n", initialValue);
				expoTwo = 1;
				//looking for the nearest power of two
				while ((expoTwo << 1) < initialValue)
				{
					expoTwo = expoTwo << 1;
					if (initialValue == 2)
						expoTwo = 0;
				}
				//if the initial number is a power of two
				if ((expoTwo << 1) == userNumber)
					initialValue = userNumber >> 1;
				//if the current number is a power of two
				else if ((expoTwo << 1) == initialValue)
					initialValue = expoTwo;
				//diffrence action
				else
					initialValue = initialValue^expoTwo;
				//switching between the players
				if (hasLead == 1)
				{
					hasLead = 0;
					louisenumber = initialValue;
				}
				else 
				{
					hasLead = 1;
					richardnumber = initialValue;
				}
			}
			if (richardnumber == 1)
			{
				printf("Richard: 1\n");
				printf("The winner is: Louise\n");
			}
			else
			{
				printf("Louise: 1\n");
				printf("The winner is: Richard\n");
			}
			break;
	
			
		default:
			return 0; break;
		}
}
		
}
