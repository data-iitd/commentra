#include <iostream>
#include <cmath> // For pow function

using namespace std;

int main() {  // The main function to execute the program logic
    long long N;  // Declare a variable N of type long long
    cin >> N;  // Read an integer input from the user and assign it to N
    int i = 1;  // Initialize the variable i to 1
    long long ans = 0;  // Initialize the variable ans to 0

    while (pow(10, i) <= N) {  // Start a while loop that continues as long as 10^i is less than or equal to N
        ans += pow(10, i) - pow(10, i - 1);  // Add the difference between 10^i and 10^(i-1) to ans
        i += 2;  // Increment i by 2 for the next iteration
    }

    ans += max(0LL, N - pow(10, i - 1) + 1);  // Add the maximum of 0 and N - 10^(i-1) + 1 to ans
    cout << ans << endl;  // Print the final value of ans

    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
