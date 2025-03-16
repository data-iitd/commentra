

#include <iostream> // Include the necessary header file for input/output

using namespace std; // Use the standard namespace

int main() {
    int n; // Declare a variable to store the number of elements
    cin >> n; // Read the number of elements from input

    int N = 100005; // Define a constant N for array size
    long long cnt[21] = {0}; // Initialize an array to count occurrences of each value shifted by 10

    // Count the occurrences of each value shifted by 10
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x + 10]++;
    }

    long long res = 0; // Initialize result variable

    // Calculate the number of pairs that sum up to 20
    for (int i = 0; i < 10; i++) {
        res += cnt[i] * cnt[20 - i];
    }

    // Special case for pairs where both elements are the same (i.e., i = 10)
    res += (cnt[10] * (cnt[10] - 1)) / 2;

    // Output the result
    cout << res << endl; // Use endl to insert a new line after printing the result

    return 0; // Return 0 to indicate successful execution of the program
}

