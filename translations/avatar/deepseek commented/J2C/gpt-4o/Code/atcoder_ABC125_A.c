#include <stdio.h> // Including the standard input-output library.

int main() {
    int sec, per_num;
    double max_sec;
    
    // Reading the first integer input which seems to be a time interval.
    scanf("%d", &sec);
    // Reading the second integer input which is a number to be added per iteration.
    scanf("%d", &per_num);
    // Reading the third integer input and adding 0.5 to it.
    int temp;
    scanf("%d", &temp);
    max_sec = temp + 0.5;
    
    int ans_num = 0; // Initializing the variable to store the result of additions.
    
    // Loop to iterate from 'sec' to 'max_sec' in steps of 'sec' and add 'per_num' to 'ans_num' each time.
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    
    // Printing the final result after the loop completes.
    printf("%d\n", ans_num);
    
    return 0; // Returning 0 to indicate successful completion of the program.
}

// <END-OF-CODE>
