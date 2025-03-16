
#include <stdio.h>

int main() {
    int a, at, b, bt, t1, t2, st, fin, now, ans;
    scanf("%d %d %d %d", &a, &at, &b, &bt);  // Reading two integers
    scanf("%d:%d", &t1, &t2);  // Reading time in "HH:MM" format

    // Calculate the start time by adjusting t1 by subtracting 5 hours and converting to minutes, then adding t2
    st = t2 + (t1 - 5) * 60;

    // Calculate the finish time by adding at to the start time
    fin = st + at;

    // Initialize now and ans variables
    now = 0;
    ans = 0;

    // Loop until now is less than fin and now is less than 1140
    while (now < fin && now < 1140) {
        if (now + bt > st) {  // Check if adding bt to now would exceed the start time
            ans += 1;  // Increment ans if the condition is met
        }
        now += b;  // Increment now by b
    }

    // Print the final value of ans
    printf("%d\n", ans);

    return 0;
}
