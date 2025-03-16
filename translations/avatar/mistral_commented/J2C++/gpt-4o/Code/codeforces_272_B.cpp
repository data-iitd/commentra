#include <iostream>     // Include iostream for input and output
#include <vector>      // Include vector for using dynamic arrays
#include <string>      // Include string for string manipulation
#include <sstream>     // Include sstream for string stream
#include <cmath>       // Include cmath for mathematical functions

using namespace std;

// Function to count the number of set bits in the binary representation of a number
int rec(long long x) {
    int answer = 0;

    // Count the number of set bits
    for (int k = 31; k >= 0; k--) {
        if ((x & (1LL << k)) != 0) // If the k-th bit is set
            answer++;               // Increment the answer
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false); // Optimize input/output
    cin.tie(nullptr);            // Untie cin from cout

    int n;                       // Number of test cases
    cin >> n;                   // Read the number of test cases

    vector<int> a(33, 0);       // Initialize a vector 'a' to store the frequency of each number

    // Read each test case and update the frequency of the number in the vector 'a'
    for (int i = 0; i < n; i++) {
        long long num;           // Variable to store the number
        cin >> num;             // Read a number
        int index = rec(num);   // Get the index of the number in the vector 'a'
        a[index]++;             // Increment the frequency of the number in the vector 'a'
    }

    // Calculate the answer
    long long answer = 0;       // Variable to store the final answer
    for (int i = 0; i < a.size(); i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1); // Calculate the sum of squares of numbers up to the current number
        answer += summ;                                 // Add the sum to the answer
    }

    cout << answer << endl;      // Print the answer
    return 0;                   // Return 0 to indicate successful execution
}

// <END-OF-CODE>
