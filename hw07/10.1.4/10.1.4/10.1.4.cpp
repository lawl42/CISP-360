#include <stdio.h>

struct date {
	int month;
	int day;
	int year;
};

int main()
{
	struct date today, *datePtr;
	datePtr = &today;

	datePtr->month = 10;
	datePtr->day = 22;
	datePtr->year = 2016;

	printf("Today's date is %i/%i/%.2i.\n", datePtr->month, datePtr->day, datePtr->year % 100);

	return 0;
}