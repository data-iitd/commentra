#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int rec(long long x) {
    int answer = 0; // Initialize the count of bits set to 1
    for (int k = 31; k >= 0; k--) { // Iterate through each bit position
        if ((x & (1LL << k)) != 0) { // Check if the k-th bit is set to 1
            answer++; // Increment the count if the bit is set
        }
    }
    return answer; // Return the count of bits set to 1
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); // Fast input/output

    int n;
    cin >> n; // Read the number of elements
    vector<int> a(33, 0); // Initialize a vector to count occurrences of bits set to 1

    // Count the number of bits set to 1 for each input number and store in vector a
    for (int i = 0; i < n; i++) {
        a[rec(cin.get())]++; // Read the number and update the count
    }

    double answer = 0; // Initialize the answer variable

    // Calculate the answer based on the given formula
    for (int i = 0; i < a.size(); i++) {
        double summ = (1 + a[i] - 1) / 2.0 * (a[i] - 1);
        answer += summ;
    }

    // Print the final answer in the required format
    cout << static_cast<long long>(answer) << endl;

    return 0; // End of the program
}

// <END-OF-CODE>
