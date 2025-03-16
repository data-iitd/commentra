#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Defining a constant for modulo operation
const int mod = 1e9 + 7;

// Function to read a list of integers from input
vector<int> readInts() {
    int n;
    cin >> n; // Read the number of integers
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i]; // Read each integer
    }
    return A;
}

// Main function to execute the logic
int main() {
    int n;
    cin >> n; // Reading an integer input for 'n'
    vector<int> A = readInts(); // Reading a list of integers
    sort(A.begin(), A.end()); // Sorting the list of integers in ascending order
    long long ans = 0; // Initializing the answer variable to accumulate the result

    // Looping through the last 2*n elements of the sorted list in reverse order
    for (int i = A.size() - 2; i >= (int)A.size() - 2 * n; i -= 2) {
        ans += A[i]; // Adding the current element to the answer
    }

    cout << ans << endl; // Printing the final accumulated answer
    return 0; // Indicating successful completion
}

// <END-OF-CODE>
