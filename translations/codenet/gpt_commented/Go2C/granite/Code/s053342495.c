
#include <stdio.h>

int main() {
    // Declare a variable to hold the day of the month
    int day;
    
    // Read an integer input from the user representing the day
    scanf("%d", &day);

    // Use a switch statement to determine the holiday based on the day
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
    
    // End of code
    return 0;
}
