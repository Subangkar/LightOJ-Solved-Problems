#include <stdio.h>
#include <string.h>

bool isLeapYearChecker(int year)
{
	bool isLeapYear = false;

	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		isLeapYear = true;
	}

	return isLeapYear;
}

class date // here duration Set = [start,end]
{
	private:

		char monthText[9];
		int day;
		int year;
		int month;

		void monthTextToInt()
		{
				 if (strstr("January", monthText)) // monthText == "January"
			{
				month = 01;
			}
			else if (strstr("February", monthText)) // February
			{
				month = 02;
			}
			else if (strstr("March", monthText)) // March
			{
				month = 03;
			}
			else if (strstr("April", monthText)) // April
			{
				month = 04;
			}
			else if (strstr("May", monthText)) // May
			{
				month = 05;
			}
			else if (strstr("June", monthText)) // June
			{
				month = 06;
			}
			else if (strstr("July", monthText)) // July
			{
				month = 07;
			}
			else if (strstr("August", monthText)) // August
			{
				month = 8;
			}
			else if (strstr("September", monthText)) // September
			{
				month = 9;
			}
			else if (strstr("October", monthText)) // October
			{
				month = 10;
			}
			else if (strstr("November", monthText)) // November
			{
				month = 11;
			}
			else if (strstr("December", monthText)) // December
			{
				month = 12;
			}

		}

	public:

		int startYear;
		int endYear;

		void scanDate() // optimized
		{
			char comma = ',';
			scanf("%s", &monthText);
			scanf("%d", &day);
			scanf("%c", &comma);
			scanf("%d", &year);

			monthTextToInt();
		}

		// needs to be optimized
		void yearStartCalc() // determins whether starting year should be counted or not
		{
			startYear = year + (4 - year % 4); // passes to next leap year

			if (month <= 2) // in Jan & Feb // if this true
			{
				startYear = year;
			}

			if (startYear % 400 != 0 && startYear % 100 == 0) // if year is divisible by 100 after +4
			{
				startYear += 4;
			}

		}


		void yearEndCalc() // determins whether ending year should be counted or not
		{
			if (isLeapYearChecker(year) == true)
			{
				if (month > 2 || month == 2 && day == 29) // true if Month start from Mar Or, Feb-29
				{
					endYear = year;
					return;
				}
			}

			// else '-1' cos the last invalid leap year would not be counted
			endYear = year - 1;
		}

};

int LeapYearCounterBetweenTwoYearDuration(int startYear, int endYear)
{
	int totalLeapYears = 0;

	int year = startYear;

	for (year = startYear; year <= endYear; year += 4)
	{
		if (year % 100 == 0 && year % 400 != 0) // year divisible by 100 is not counted else every year divisible by 4 '+1'
		{
			continue;
		}
		totalLeapYears++;
		//	year += 4;
	}

	return totalLeapYears;
}


int main()
{
	int testCase = 0;
	int caseCounter = 1;

	scanf("%d", &testCase);

	date year1, year2;

	while (caseCounter <= testCase)
	{
		year1.scanDate();
		year2.scanDate();
		
		year1.yearStartCalc();
		year2.yearEndCalc();

		int leapYearsDuringThisDuration = LeapYearCounterBetweenTwoYearDuration(year1.startYear,year2.endYear);

		printf("Case %d: %d\n", caseCounter, leapYearsDuringThisDuration);
		caseCounter++;
	}

	return 0;
}






// This exceeds time limit :: takes 1.92s
/*

#include <stdio.h>
#include <string.h>

bool isLeapYearChecker(int year)
{
	bool isLeapYear = false;

	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		isLeapYear = true;
	}

	return isLeapYear;
}

class date // here duration Set = [start,end]
{
private:

	char monthText[10];
	int day;
	int year;
	int month;

	void monthTextToInt()
	{
		if (strstr("January", monthText)) // monthText == "January"
		{
			month = 01;
		}
		else if (strstr("February", monthText)) // February
		{
			month = 02;
		}
		else if (strstr("March", monthText)) // March
		{
			month = 03;
		}
		else if (strstr("April", monthText)) // April
		{
			month = 04;
		}
		else if (strstr("May", monthText)) // May
		{
			month = 05;
		}
		else if (strstr("June", monthText)) // June
		{
			month = 06;
		}
		else if (strstr("July", monthText)) // July
		{
			month = 07;
		}
		else if (strstr("August", monthText)) // August
		{
			month = 8;
		}
		else if (strstr("September", monthText)) // September
		{
			month = 9;
		}
		else if (strstr("October", monthText)) // October
		{
			month = 10;
		}
		else if (strstr("November", monthText)) // November
		{
			month = 11;
		}
		else if (strstr("December", monthText)) // December
		{
			month = 12;
		}

	}

public:

	int startYear;
	int endYear;

	void scanDate() // optimized
	{
		char comma = ',';
		scanf("%s", &monthText);
		scanf("%d", &day);
		scanf("%c", &comma);
		scanf("%d", &year);

		monthTextToInt();
	}

	void yearStartCalc() // determins whether starting year should be counted or not
	{
		if (isLeapYearChecker(year) == true) // year % 400 == 0 || year % 4 == 0 && year % 100 != 0
		{
			if (month <= 2) // in Jan & Feb // if this true
			{
				startYear = year;
				return;
			}
		}

		startYear = year + (4 - year % 4); // passes to next leap year

		if (startYear % 400 != 0 && startYear % 100 == 0) // if year is divisible by 100 after +4
		{
			startYear += 4;
		}

	}

	void yearEndCalc() // determins whether ending year should be counted or not
	{
		if (isLeapYearChecker(year) == true)
		{
			if (month > 2 || month == 2 && day == 29) // true if Month start from Mar Or, Feb-29
			{
				endYear = year;
				return;
			}
		}

		// else '-1' cos the last invalid leap year would not be counted
		endYear = year - 1;
	}

};

int LeapYearCounterBetweenTwoYearDuration(int startYear, int endYear)
{
	int totalLeapYears = 0;

	int year = startYear;

	for (year = startYear; year <= endYear; year += 4)
	{
		if (year % 100 == 0 && year % 400 != 0) // year divisible by 100 is not counted else every year divisible by 4 '+1'
		{
			continue;
		}
		totalLeapYears++;
		//	year += 4;
	}

	return totalLeapYears;
}


int main()
{
	int testCase = 0;
	int caseCounter = 1;

	scanf("%d", &testCase);

	date year1, year2;

	while (caseCounter <= testCase)
	{
		year1.scanDate();
		year2.scanDate();

		year1.yearStartCalc();
		year2.yearEndCalc();

		int leapYearsDuringThisDuration = LeapYearCounterBetweenTwoYearDuration(year1.startYear, year2.endYear);

		printf("Case %d: %d\n", caseCounter, leapYearsDuringThisDuration);
		caseCounter++;
	}

	return 0;
}


*/