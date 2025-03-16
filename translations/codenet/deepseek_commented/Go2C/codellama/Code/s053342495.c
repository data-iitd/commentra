#include <stdio.h>

int main() {
	// Declare a variable to store the day of Christmas
	int day;
	// Read an integer input from the user
	scanf("%d", &day);

	// Use a switch statement to determine the day of Christmas
	switch (day) {
	case 25:
		// If the day is Christmas (December 25), print "Christmas"
		printf("Christmas\n");
		break;
	case 24:
		// If the day is Christmas Eve (December 24), print "Christmas Eve"
		printf("Christmas Eve\n");
		break;
	case 23:
		// If the day is Christmas Eve Eve (December 23), print "Christmas Eve Eve"
		printf("Christmas Eve Eve\n");
		break;
	case 22:
		// If the day is Christmas Eve Eve Eve (December 22), print "Christmas Eve Eve Eve"
		printf("Christmas Eve Eve Eve\n");
		break;
	}

	return 0;
}
