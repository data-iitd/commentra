#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Read the number of test cases
    int N;
    cin >> N;

    // Read the array V of size N
    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // Read the array C of size N
    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    // Initialize an empty vector to store the differences between V and C
    vector<int> differences;

    // Initialize variables to store the current difference and the sum of differences
    int ans = 0;
    int X = 0;
    int Y = 0;

    // Iterate through each index i from 0 to N-1
    for (int i = 0; i < N; i++) {
        // If the difference between V[i] and C[i] is positive
        if (V[i] - C[i] > 0) {
            // Update X and Y with the respective values from V and C at index i
            X = V[i];
            Y = C[i];
            // Append the difference X-Y to the vector
            differences.push_back(X - Y);
            // Update the sum of differences
            ans += X - Y;
        }
    }

    // Print the sum of all the elements in the vector
    cout << accumulate(differences.begin(), differences.end(), 0) << endl;
    // Print the sum of all the differences between V and C
    cout << ans << endl;

    return 0;
}
// <END-OF-CODE>
