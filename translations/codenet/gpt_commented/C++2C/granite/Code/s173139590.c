
#include <stdio.h>

int main() {
    // Declare a variable to hold the number of submissions
    int n;
    // Read the number of submissions from the user
    scanf("%d", &n);

    // Initialize counters for different result types
    int ac_count = 0; // Count of Accepted submissions
    int wa_count = 0; // Count of Wrong Answer submissions
    int tle_count = 0; // Count of Time Limit Exceeded submissions
    int re_count = 0; // Count of Runtime Error submissions

    // Loop through each submission
    for (int i = 0; i < n; ++i) {
        char s[10]; // Variable to hold the result of the current submission
        // Read the result of the current submission
        scanf("%s", s);

        // Increment the respective counter based on the result
        if (strcmp(s, "AC") == 0) {
            ac_count += 1; // Increment Accepted count
        } else if (strcmp(s, "WA") == 0) {
            wa_count += 1; // Increment Wrong Answer count
        } else if (strcmp(s, "TLE") == 0) {
            tle_count += 1; // Increment Time Limit Exceeded count
        } else if (strcmp(s, "RE") == 0) {
            re_count += 1; // Increment Runtime Error count
        }
    }

    // Output the counts of each result type
    printf("AC x %d\n", ac_count); // Display Accepted count
    printf("WA x %d\n", wa_count); // Display Wrong Answer count
    printf("TLE x %d\n", tle_count); // Display Time Limit Exceeded count
    printf("RE x %d\n", re_count); // Display Runtime Error count
}
