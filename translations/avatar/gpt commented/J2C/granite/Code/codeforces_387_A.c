
#include <stdio.h> // Include the standard input/output library
#include <time.h> // Include the time library for working with time

int main() { // Main function
    char s[9], t[9]; // Declare character arrays to store the time inputs
    int h1, m1, h2, m2; // Declare integer variables to store the hours and minutes of the two times
    
    // Read two time inputs in "HH:MM" format and store them in the character arrays
    scanf("%s %s", s, t);
    
    // Extract the hours and minutes from the character arrays and store them in the integer variables
    sscanf(s, "%d:%d", &h1, &m1);
    sscanf(t, "%d:%d", &h2, &m2);
    
    // Calculate the difference between the two times in hours and minutes
    int hours_diff = h1 - h2;
    int minutes_diff = m1 - m2;
    
    // If the minutes difference is negative, adjust the hours difference accordingly
    if (minutes_diff < 0) {
        minutes_diff += 60;
        hours_diff--;
    }
    
    // Print the difference between the two times in "HH:MM" format
    printf("%d:%02d\n", hours_diff, minutes_diff);
    
    return 0; // Return 0 to indicate successful execution
}
