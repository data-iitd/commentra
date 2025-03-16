#include <stdio.h>
#include <math.h>

void printLong(long ans) {
    printf("%ld\n", ans);
}

void printInt(int ans) {
    printf("%d\n", ans);
}

void printString(const char* ans) {
    printf("%s\n", ans);
}

void printEmpty() {
    printf("\n");
}

int main() {
    // Read a long integer N from user input
    long N;
    scanf("%ld", &N);
    
    // Initialize a variable to hold the minimum value
    long min = 0;
    
    // Loop to read five long integers and find the minimum
    for (int i = 0; i < 5; i++) {
        long value;
        scanf("%ld", &value);
        
        // For the first iteration, directly assign the value to min
        if (i == 0) {
            min = value;
        } else {
            // For subsequent iterations, update min if a smaller value is found
            if (value < min) {
                min = value;
            }
        }
    }
    
    // Calculate the result by dividing N by min, rounding up, and adding 4
    long result = (long)ceil((double)N / min) + 4;
    printLong(result);
    
    return 0;
}

// <END-OF-CODE>
