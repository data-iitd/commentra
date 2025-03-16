
#include <stdio.h>

int main ( void ) {
    // Create a new Scanner object to read input from the standard input stream
    int sec, per_num, max_sec ;
    scanf ( "%d %d %d", &sec, &per_num, &max_sec ) ;

    // Convert the last input (max_sec) to a double type and add 0.5 to it to get the maximum number of seconds with a fractional part
    double max_sec = ( double ) max_sec + 0.5 ;

    // Initialize a counter variable ans_num to zero
    int ans_num = 0 ;

    // Start a for loop that runs from the initial value sec to the final value max_sec with a step size of sec. In each iteration of the loop, add per_num to ans_num
    for ( int i = sec ; i < max_sec ; i += sec ) {
        ans_num += per_num ;
    }

    // Print the result ans_num to the standard output stream
    printf ( "%d\n", ans_num ) ;

    // Close the Scanner object to release the system resources
    return 0 ;
}
