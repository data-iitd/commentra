#include <stdio.h> // Include the standard input-output library

int main() {
    // Declare variables for T, S, and q
    int T, S, q;
    
    // Read the values of T, S, and q from user input
    scanf("%d %d %d", &T, &S, &q);
    
    // Initialize the variable `previous` with the value of S
    long previous = S;
    
    // Initialize the variable `answer` with the value 0
    int answer = 0;
    
    // Enter a while loop that continues until `previous` is less than T
    while (previous < T) {
        // Inside the loop, multiply `previous` by q and increment the `answer` by 1
        previous *= q;
        answer++;
    }
    
    // After the loop, print the value of `answer`
    printf("%d\n", answer);
    
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
