#include <stdio.h>

int main() {
    int a, at, b, bt;
    scanf("%d %d", &a, &at);  // Reading two integers
    scanf("%d %d", &b, &bt);  // Reading two more integers

    int t1, t2;
    scanf("%d:%d", &t1, &t2);  // Reading time in "HH:MM" format

    // Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
    int st = t2 + (t1 - 5) * 60;

    // Calculate the finish time by adding at to the start time
    int fin = st + at;

    // Initialize now and ans variables
    int now = 0;
    int ans = 0;

    // Loop until now is less than fin and now is less than 1140
    while (now < fin && now < 1140) {
        if (now + bt > st) {  // Check if adding bt to now would exceed the start time
            ans++;  // Increment ans if the condition is met
        }
        now += b;  // Increment now by b
    }

    // Print the final value of ans
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
