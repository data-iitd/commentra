#include <iostream> // Include the iostream library for input and output

using namespace std;

int main() {
    // Create a variable to hold the integer input from the user
    int n;
    
    // Read an integer input from the user
    cin >> n;
    
    // Initialize a variable to hold the final result
    long long ans = 0;
    
    // Loop through each integer from 1 to n (inclusive)
    for (int i = 1; i <= n; i++) {
        // Calculate the contribution of the current integer i to the result
        // This involves multiplying i by the number of times i fits into n
        // and summing up the series of numbers from 1 to (n / i)
        ans += (long long)i * (n / i) * ((n / i) + 1) / 2;
    }
    
    // Output the final result
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
