
#include <stdio.h> // Importing stdio.h for input/output operations

int main() {
    // Declaring and initializing an integer variable n
    int n;
    scanf("%d", &n); // Reading an integer input from the user using scanf
    
    // Calling the solve function with the input integer
    solve(n);
    
    return 0; // Returning 0 to indicate successful execution
}

void solve(int n) {
    // Calculating and printing the result based on the input integer n
    // The formula calculates (n / 3) * 2 and adds 1 if n is not divisible by 3
    printf("%d\n", (n / 3) * 2 + (n % 3 == 0? 0 : 1));
}

