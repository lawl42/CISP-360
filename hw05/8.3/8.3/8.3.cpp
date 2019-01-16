// Program to find elapsed time

#include <stdio.h>

// time
struct time
{
	int hours;
	int minutes;
	int seconds;
};

// convert to seconds
int to_seconds(struct time time)
{
	return time.hours * 3600 + time.minutes * 60 + time.seconds;
}

// convert to real time
struct time to_realtime(int seconds)
{
	struct time time;
	time.hours = seconds / 3600;
	seconds %= 3600;
	time.minutes = seconds / 60;
	seconds %= 60;
	time.seconds = seconds;
	return time;
}

// elapsed time
void elapsed_time(struct time time1, struct time time2)
{
	struct time elapsed;
	int diffInSeconds = to_seconds(time2) - to_seconds(time1);

	if (diffInSeconds < 0)
		elapsed = to_realtime(diffInSeconds + 86400); // 86400 is number of seconds in 1 day 60 * 60 * 24
	else
		elapsed = to_realtime(diffInSeconds);

	printf("Elapsed time: %i hours, %i minutes, and %i seconds.\n", elapsed.hours, elapsed.minutes, elapsed.seconds);
}

int main(void)
{
	struct time time1, time2;
	printf("First time (hh:mm:ss): ");
	scanf("%i:%i:%i", &time1.hours, &time1.minutes, &time1.seconds);
	printf("Second time (hh:mm:ss): ");
	scanf("%i:%i:%i", &time2.hours, &time2.minutes, &time2.seconds);

	elapsed_time(time1, time2);
	return 0;
}