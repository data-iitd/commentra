#include <iostream> // Include the iostream library for input and output

using namespace std;

int main() {
    int n; // Declare an integer variable n
    cin >> n; // Read an integer n from the user
    long long ans = 0; // Initialize the variable ans to 0

    // Loop from 1 to n (inclusive)
    for (int i = 1; i <= n; i++) {
        // Calculate a value based on the current value of i and the variable n
        long long term = n / i;
        long long sum = term * (term + 1) / 2;
        ans += i * sum;
    }

    // Print the value of ans
    cout << ans << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
