#include <stdio.h>

int main() {
    // Declare variables
    int sec, per_num, max_sec;
    double max_sec_double;
    int ans_num = 0;

    // Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    scanf("%d", &sec);       // Read the number of seconds
    scanf("%d", &per_num);   // Read the number of periods
    scanf("%d", &max_sec);   // Read the total number of seconds

    // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
    max_sec_double = (double)max_sec + 0.5; // Convert max_sec to double and add 0.5

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for (int i = sec; i < max_sec_double; i += sec) {
        ans_num += per_num;
    }

    // Print the result ans_num to the standard output stream
    printf("%d\n", ans_num);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
