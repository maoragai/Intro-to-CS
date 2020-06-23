/******************************************
*Student name: Agai Maor
*Student ID:305544546
*Submit Info:Agaimao
*Exercise name: ex5
******************************************/

#include "Mission3.h"
#include <stdio.h>

/************************************************************************
* function name: 	cpyString										*
* The Input:	two strings and their length					*
* The output:	two identical strings		*
* The Function operation:  the function takes an array and copies its values to another	*
*************************************************************************/

void cpyString(char original[], char duplicate[], int n)
{
	int i;
	for (i = 0; i <= n; i++)
		duplicate[i] = original[i];
}
/************************************************************************
* function name: canAnagramHelper											*
* The Input:	two strings a postion in the string and the string length		*
* The output:	an anagram of the string which is a palindrome (if exists)	*
* The Function operation: the function uses a recursion to creat all the strings anagrams*
*************************************************************************/
int canAnagramHelper(char originalStr[], char str[], int position, int lengthStr)
{
	int i;
	char swtchHelper;
	if (position == lengthStr)
		if ((isPalindrom(str, lengthStr) == 1) && (str[lengthStr + 1] != '0')) {
			printf("The string %s has the palindrome %s\n", originalStr, str);
			str[lengthStr + 1] = '0';
		}
	for (i = position; i <lengthStr; i++)
	{
		swtchHelper = str[position];
		str[position] = str[i];
		str[i] = swtchHelper;
		if (str[lengthStr + 1] == '0')
			return;
		canAnagramHelper(originalStr, str, position + 1, lengthStr);
	}

}
/************************************************************************
* function name: isPalindrom											*
* The Input: a tring and its length			*
* The output:	returns a value if the string is a palindrom	*
* The Function operation: the function check the string chars for identities 	*
*************************************************************************/
int isPalindrom(char string[], int n)
{
	int i;
	for (i = 0; i < n / 2; i++)
	{
		if (string[i] != string[(n - 1) - i])
			return 0;
	}
	return 1;
}
/************************************************************************
* function name: sizeString											*
* The Input:a string						*
* The output:an int represents the length of the string	*
* The Function operation: the function counts the chars in the string 	*
*************************************************************************/
int sizeString(char string[])
{
	int n = 0;
	while (1)
	{
		if (string[n] == '\0')
			break;
		else
			n++;
	}
	return n;
}
/************************************************************************
* function name: canAnagram											*
* The Input:	a string					*
* The output:	prints out if an anagram of the string is a palindrome	*
* The Function operation:  	*
*************************************************************************/
void canAnagram(char str[])
{
	int n = 0;
	char strReplica[MAX_STRING_LENGTH];
	//gets the size of the string
	n = sizeString(str);
	//creat a replica for the string
	cpyString(str, strReplica, n);
	//use  an helper to determine if the string has an anagram which is a palindrome
	canAnagramHelper(str, strReplica, 0, n);
	if (strReplica[n + 1] != '0')
		printf("The string %s does not have a palindrome\n", str);
}
/************************************************************************
Fill comment
*************************************************************************/
void mission3()
{
	int i;
	char str[MAX_STRING_LENGTH];
	printf("Please enter the string:\n");
	scanf("%s", str);				// input the str
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] < 'a' || str[i] > 'z')
			return;
	}
	canAnagram(str);
}