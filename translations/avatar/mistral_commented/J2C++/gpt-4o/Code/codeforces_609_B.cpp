// Importing the required header for input-output operations
#include <iostream>
#include <vector>

using namespace std;

// Main function is the entry point of the C++ application
int main() {
    // Creating variables to store the input integers n and m
    int n, m;

    // Reading the first integer input n from the user
    cin >> n;

    // Reading the second integer input m from the user
    cin >> m;

    // Creating a vector arr of size n to store the input integers
    vector<int> arr(n);

    // Creating a vector gen of size 11 to store the count of each integer occurrence
    vector<int> gen(11, 0);

    // Reading the input integers and storing them in the arr vector
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // Incrementing the count of the arr[i] in the gen vector
        gen[arr[i]]++;
    }

    // Calculating the answer
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= m; k++) {
            // Skipping the case when i and k are equal to avoid double counting
            if (i != k) {
                // Multiplying the count of i and k and adding it to the answer
                ans += static_cast<long long>(gen[i]) * gen[k];
            }
        }
    }

    // Printing the answer divided by 2
    cout << ans / 2 << endl;

    return 0;
}

// <END-OF-CODE>
