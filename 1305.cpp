#include <iostream>
#include <stdio.h>

using namespace std;

struct point // (x,y) && (x,y,z)
{
	double x;
	double y;
	double z;

	point operator * (double constant)
	{
		point multipliedPoint;

		multipliedPoint.x = this->x * constant;
		multipliedPoint.y = this->y * constant;
		multipliedPoint.z = this->z * constant;

		return multipliedPoint;
	}

	point operator - (point secondPoint)
	{
		secondPoint.x = this->x - secondPoint.x;
		secondPoint.y = this->y - secondPoint.y;
		secondPoint.z = this->z - secondPoint.z;

		return secondPoint;
	}
};

double modl(double num)
{
	if (num == 0) { return 0; }

	else if (num < 0) { return -num; }

	else { return num; }
}

double limitedAreaOfThreeTwoDPoints(point p1, point p2, point p3)
{
	double delABC = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);

	double area = 0.5 * modl(delABC);

	return area;
}

point midPoint(point p1, point p2)
{
	point midP;

	midP.x = (p1.x + p2.x) / 2;
	midP.y = (p1.y + p2.y) / 2;

	return midP;
}

point fourthPointOfParallelogram(point A, point B, point C) // returns D @ ABCD (B,D) && (A,C) are composities
{
	point D;

	point O;

	O = midPoint(A, C);

	D = O * 2 - B;

	return D;
}

int main()
{
	int testCase = 0;

	scanf("%d", &testCase);


	int caseCounter = 1;

	while (caseCounter <= testCase)
	{
		point A, B, C, D;

		cin >> A.x;
		cin >> A.y;
		cin >> B.x; 
		cin >> B.y; 
		cin >> C.x;
		cin >> C.y;

//		scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);

		D = fourthPointOfParallelogram(A, B, C);

		int area = 2 * limitedAreaOfThreeTwoDPoints(A, B, C);

		printf("Case %d: %.0f %.0f %d\n", caseCounter, D.x, D.y, area);

		caseCounter++;
	}

	return 0;
}
