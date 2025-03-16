#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for using vectors

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Read the first integer n and the second integer m from input

    vector<int> arr(n); // Declare and initialize a vector to store n integers
    vector<int> gen(11, 0); // Declare and initialize a vector to count occurrences of integers

    // Read n integers from input and store them in arr, and count their occurrences in gen
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        gen[arr[i]]++;
    }

    long long ans = 0; // Declare a variable to store the result

    // Calculate the number of pairs (i, k) where i ≠ k and gen[i] and gen[k] are non-zero
    for (int i = 1; i <= m; i++) {
        for (int k = 1; k <= m; k++) {
            if (i != k) {
                ans += (long long) gen[i] * gen[k];
            }
        }
    }

    // Print the result, which is half of the calculated pairs
    cout << ans / 2 << endl;

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
