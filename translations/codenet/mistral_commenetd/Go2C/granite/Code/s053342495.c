

#include <stdio.h>

int main() {
    // Declare a variable named day of type int
    int day;

    // Read an integer value from the standard input using scanf()
    scanf("%d", &day);

    // Use a switch statement to determine the name of the day based on the given day number
    switch (day) {
    case 25:
        // If the day is 25, print "Christmas"
        printf("Christmas\n");
        break;
    case 24:
        // If the day is 24, print "Christmas Eve"
        printf("Christmas Eve\n");
        break;
    case 23:
        // If the day is 23, print "Christmas Eve Eve"
        printf("Christmas Eve Eve\n");
        break;
    case 22:
        // If the day is 22, print "Christmas Eve Eve Eve"
        printf("Christmas Eve Eve Eve\n");
        break;
    }

    // End the program
    return 0;
}
