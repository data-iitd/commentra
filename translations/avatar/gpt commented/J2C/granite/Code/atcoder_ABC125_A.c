
#include <stdio.h> // Including the standard input/output library

int main() {
    // Reading the number of seconds from user input
    int sec;
    scanf("%d", &sec);
    
    // Reading the number of items per interval from user input
    int per_num;
    scanf("%d", &per_num);
    
    // Reading the maximum time limit, adding 0.5 to ensure proper rounding
    double max_sec;
    scanf("%lf", &max_sec);
    
    // Initializing a variable to hold the total count of items
    int ans_num = 0;
    
    // Looping from'sec' to'max_sec' in increments of'sec'
    for (int i = sec; i < max_sec; i += sec) {
        // Accumulating the total number of items produced
        ans_num += per_num;
    }
    
    // Outputting the total number of items produced
    printf("%d\n", ans_num);
    
    return 0; // Returning 0 to indicate successful program execution
}
