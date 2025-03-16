#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for using vectors

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    const int N = 1e5 + 5; // Define a constant N for array size
    vector<long long> cnt(21, 0); // Initialize a vector to count occurrences of each value shifted by 10

    // Count the occurrences of each value shifted by 10
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value; // Read each value
        cnt[value + 10]++; // Increment the count for the shifted value
    }

    long long res = 0; // Initialize result variable

    // Calculate the number of pairs that sum up to 20
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    // Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Output the result
    cout << res << endl;

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
