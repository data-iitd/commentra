
#include <stdio.h> // Including the standard input/output library.

int main() {
    int sec, per_num, max_sec, ans_num = 0; // Declaring and initializing the variables.
    
    scanf("%d %d %d", &sec, &per_num, &max_sec); // Reading the input values using scanf function.
    
    // Loop to iterate from'sec' to'max_sec' in steps of'sec' and add 'per_num' to 'ans_num' each time.
    for (int i = sec; i < max_sec; i += sec) {
        ans_num += per_num;
    }
    
    printf("%d", ans_num); // Printing the final result using printf function.
    
    return 0; // Returning 0 to indicate successful execution of the program.
}

