#include <stdio.h>

void main()
{
	int testCase = 0;

	scanf("%d", &testCase);

	int caseCounter = 1;

	while (caseCounter <= testCase)
	{
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);

		printf("Case %d: %d\n", caseCounter, num1 + num2);

		caseCounter++;
	}
}