#include <stdio.h>

int reverseNum(int num) // 4321 > 1234
{
	int reversedNum = 0;

	while (num > 0)
	{
		int thisBit = num % 10;

		reversedNum = (reversedNum * 10) + thisBit; // pass the prev bit next & sum this bit

		num /= 10;
	}

	return reversedNum;
}

int main()
{
	int testCase = 0;
	int caseCounter = 1;
	int num = 10000000000;

	scanf("%d", &testCase);

	while (caseCounter <= testCase)
	{
		scanf("%d", &num);

		if (num == reverseNum(num))
		{
			printf("Case %d: Yes\n", caseCounter);
		}
		else
		{
			printf("Case %d: No\n", caseCounter);
		}
		caseCounter++;
	}


	return 0;
}

/*Here Used Array*/
/*
#include<iostream>
#include<stdio.h>
#include<string.h>

#define ENTER '\n'

bool paindrome(char nums[])
{
	bool palin = true;

	int maxCounter = strlen(nums) - 2; // cos last one is '\0'

	for (int minCounter = 0; minCounter < maxCounter; minCounter++, maxCounter--)
	{
		if (nums[minCounter] != nums[maxCounter])
		{
			palin = false;
			break;
		}
	}

	return palin;
}


int main()
{
	int testCase = 0;
	int caseCounter = 1;

	scanf("%d", &testCase);
	fflush(stdin);

	char num[] = "100000000000000000000000000000000000000000000000000000000000000";

	//    char *nums = num ;

	while (caseCounter <= testCase)
	{
		int index = 0;
		while (scanf("%c", &num[index]) && num[index++] != ENTER);

		bool isPalindromic = paindrome(num);

		if (isPalindromic == true)
		{
			printf("Case %d: Yes\n", caseCounter);
		}
		else
		{
			printf("Case %d: No\n", caseCounter);
		}
		caseCounter++;
	}
	return 0;
}
*/


/*Used Pointer*/ // Works but runtime error
/*
// Works but runtime error

#include<iostream>
#include<stdio.h>
#include<string.h>

bool paindrome(char *nums)
{
bool palin = true ;

int maxCounter = strlen(nums)-1 ; // cos last one is '\0'

for(int minCounter=0 ; minCounter<maxCounter ; minCounter++,maxCounter-- )
{
if( *(nums+minCounter)!=*(nums+maxCounter) )
{
palin = false ;
break ;
}
}

return palin ;
}


int main()
{
int testCase = 0 ;
int caseCounter = 1 ;

scanf("%d", &testCase);
fflush(stdin);

char num[] = "100000000000000000000000000000000000000000000000000000000000000" ;

char *nums = num ;

while (caseCounter <= testCase)
{
gets(nums);

bool isPalindromic = paindrome(nums);

if (isPalindromic == true)
{
printf("Case %d: Yes\n", caseCounter);
}
else
{
printf("Case %d: No\n", caseCounter);
}
caseCounter++;
}
return 0 ;
}
*/