#include <stdio.h>
#include <math.h>


int main()
{
	int testCase = 0;
	int caseCounter = 1;
	scanf("%d", &testCase);
	
	int a, b, c;
	while (caseCounter <= testCase)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		if ( pow(c,2)==pow(a,2)+pow(b,2) || pow(a, 2) == pow(b, 2) + pow(c, 2) || pow(b, 2) == pow(a, 2) + pow(c, 2) )
		{
			printf("Case %d: yes\n", caseCounter);
		}
		else
		{
			printf("Case %d: no\n", caseCounter);
		}

		caseCounter++;
	}
}