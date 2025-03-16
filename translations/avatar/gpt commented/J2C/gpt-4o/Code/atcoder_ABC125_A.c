#include <stdio.h> // Including standard input-output library

int main() {
    // Declaring variables
    int sec, per_num, ans_num = 0;
    double max_sec;

    // Reading the number of seconds from user input
    scanf("%d", &sec);
    
    // Reading the number of items per interval from user input
    scanf("%d", &per_num);
    
    // Reading the maximum time limit and adding 0.5 for proper rounding
    scanf("%lf", &max_sec);
    max_sec += 0.5;

    // Looping from 'sec' to 'max_sec' in increments of 'sec'
    for (int i = sec; i < max_sec; i += sec) {
        // Accumulating the total number of items produced
        ans_num += per_num;
    }
    
    // Outputting the total number of items produced
    printf("%d\n", ans_num);

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
