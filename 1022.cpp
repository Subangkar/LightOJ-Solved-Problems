#include <stdio.h>
#include <math.h>

#define pi 2*acos(0.0)

void main()
{
	int testCase = 0;
	scanf("%d", &testCase);

	int caseCounter = 1;

	while (caseCounter <= testCase)
	{
		double radius = 0;
		scanf("%lf", &radius);

		double shadedArea = (4-pi) * pow(radius, 2);

		printf("Case %d: %.2f\n", caseCounter, shadedArea);

		caseCounter++;
	}

}