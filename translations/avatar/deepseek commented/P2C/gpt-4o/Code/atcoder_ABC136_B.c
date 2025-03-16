#include <stdio.h>
#include <math.h>

int main() {  // The main function to execute the program logic
    int N;  // Declare an integer variable N
    scanf("%d", &N);  // Read an integer input from the user and assign it to N
    int i = 1;  // Initialize the variable i to 1
    long long ans = 0;  // Initialize the variable ans to 0 (using long long for larger values)
    
    while (pow(10, i) <= N) {  // Start a while loop that continues as long as 10^i is less than or equal to N
        ans += (pow(10, i) - pow(10, i - 1));  // Add the difference between 10^i and 10^(i-1) to ans
        i += 2;  // Increment i by 2 for the next iteration
    }
    
    ans += fmax(0, N - pow(10, i - 1) + 1);  // Add the maximum of 0 and N - 10^(i-1) + 1 to ans
    printf("%lld\n", ans);  // Print the final value of ans

    return 0;  // Return 0 to indicate successful execution
}  // End of main function

// <END-OF-CODE>
