// Program that finds the number of days between dates

#include <stdio.h>

// date
struct date
{
	int year;
	int month;
	int day;
};

int f(int year, int month)
{
	if (month <= 2)
		return year - 1;
	else
		return year;
}

int g(int month)
{
	if (month <= 2)
		return month + 13;
	else
		return month + 1;
}

// Calculating N
int N(struct date date)
{
	int duration = 1461 * f(date.year, date.month) / 4 + 153 * g(date.month) / 5 + date.day;
	if ((date.month <= 2 && date.day <= 31 && date.year <= 1800) || (date.year < 1800))
		return duration + 2;
	else if ((date.month <= 2 && date.day <= 31 && date.year <= 1900) || (date.year < 1900))
		return duration + 1;
	else
		return duration;
}

int main(void)
{
	struct date first, second;
	printf("First date (mm/dd/yyyy): ");
	scanf("%i/%i/%i", &first.month, &first.day, &first.year);
	printf("Second date (mm/dd/yyyy): ");
	scanf("%i/%i/%i", &second.month, &second.day, &second.year);

	int i1 = N(first);
	int	i2 = N(second);

	if (first.month < 3 && first.year == 1700 || first.year < 1700) {
		printf("Not a valid date.\nPlease enter from March 1, 1700 onwards.\n");
	}
	else {
		printf("\nNumber of elapsed days\t= %i - %i", i1, i2);
		printf("\n                      \t= %i\n", i2 - i1);
	}

	return 0;
}