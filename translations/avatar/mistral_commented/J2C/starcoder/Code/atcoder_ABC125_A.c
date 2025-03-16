#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Declare a variable to store the number of seconds
    int sec;

    // Declare a variable to store the number of periods
    int per_num;

    // Declare a variable to store the total number of seconds
    int max_sec;

    // Declare a variable to store the number of periods
    int ans_num;

    // Read three integers from the standard input: the number of seconds, the number of periods, and the total number of seconds
    scanf("%d %d %d", &sec, &per_num, &max_sec);

    // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
    double max_sec = ( double ) max_sec + 0.5 ;

    // Initialize a counter variable ans_num to zero
    ans_num = 0;

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for ( int i = sec ; i < max_sec ; i += sec ) {
        ans_num += per_num ;
    }

    // Print the result ans_num to the standard output stream
    printf("%d", ans_num);

    // Return 0 to the operating system
    return 0;
}

