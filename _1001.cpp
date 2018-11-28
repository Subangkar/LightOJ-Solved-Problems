#include <stdio.h>
#include <stdlib.h>

void main()
{
	int testCase = 0;

	scanf("%d", &testCase);

	int caseCounter = 1;

	while (caseCounter <= testCase)
	{
		int sum, num1;
		scanf("%d",&sum );

		num1 = rand() % sum;

		printf("%d %d\n", num1, sum - num1);

		caseCounter++;
	}

}