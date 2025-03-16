#include <stdio.h>

int main() {
    // Initialize variables
    int T, S, q;
    
    // Read the first integer `T` from the input
    scanf("%d", &T);
    
    // Read the second integer `S` from the input
    scanf("%d", &S);
    
    // Read the third integer `q` from the input
    scanf("%d", &q);
    
    // Initialize the variable `previous` with the value of `S`
    long previous = S;
    
    // Initialize the variable `answer` with the value of 0
    int answer = 0;
    
    // Start a while loop that continues as long as `previous` is less than `T`
    while (previous < T) {
        // Increment the value of `answer` by 1
        answer++;
        
        // Multiply the value of `previous` by `q`
        previous *= q;
    }
    
    // Print the value of `answer` to the standard output stream
    printf("%d\n", answer);
    
    return 0;
}

// <END-OF-CODE>
