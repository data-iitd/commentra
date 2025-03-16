
#include <stdio.h>
#include <stdlib.h>

// Define the solve function that takes a test case number as an argument
void solve ( int tc ) {
    // Read an integer input from standard input
    int a;
    scanf ( "%d", &a );
    // Print 1 if the input is 0, otherwise print 0
    printf ( "%d\n", a == 0 ? 1 : 0 );
}

// Set the number of test cases to 1 and initialize the current test case number
int tcs = 1;
int tc = 1;

// Enter a while loop that continues as long as the current test case number is less than or equal to the total number of test cases
while ( tc <= tcs ) {
    // Call the solve function with the current test case number and increment the current test case number
    solve ( tc );
    tc++;
}

