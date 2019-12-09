#include <bits/stdc++.h>

using namespace std;

int main()
{
	int testCase = 0;

	scanf("%d", &testCase);

	int caseCounter = 1;

	while (caseCounter <= testCase)
	{
		int sum, num1;
		scanf("%d",&sum );

		num1 = sum/2;

		printf("%d %d\n", num1, sum - num1);

		caseCounter++;
	}
    return 0;
}