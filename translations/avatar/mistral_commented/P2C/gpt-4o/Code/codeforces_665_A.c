#include <stdio.h>

int main() {
    int a, at;
    // Read the first pair of integers (a and at) from the user input
    scanf("%d %d", &a, &at);

    int b, bt;
    // Read the second pair of integers (b and bt) from the user input
    scanf("%d %d", &b, &bt);

    int t1, t2;
    // Read the start time (t1) and end time (t2) from the user input in the format "HH:MM"
    scanf("%d:%d", &t1, &t2);

    int st = t2 + (t1 - 5) * 60;  // Calculate the start time in seconds
    // Convert the start time from HH:MM format to seconds

    int fin = st + at;  // Calculate the finish time in seconds
    // Calculate the finish time in seconds

    int now = 0;  // Initialize the current time to zero
    int ans = 0;  // Initialize the answer to zero

    // Loop through the time until the current time is less than the finish time and less than 1140 (11:00 PM)
    while (now < fin && now < 1140) {
        // If the next event starts after the current time, increment the answer
        if (now + bt > st) {
            ans += 1;
        }
        // Increment the current time by the duration of the next event
        now += b;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
// <END-OF-CODE>
