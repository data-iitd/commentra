#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    // Read two integers N and K from input
    int N, K;
    cin >> N >> K;

    // Read a list of integers from input
    vector<int> lst(N);
    for (int i = 0; i < N; ++i) {
        cin >> lst[i];
    }

    // Initialize vectors to hold positive and negative numbers
    vector<int> lst_p;
    vector<int> lst_m;

    // Iterate through the list to categorize numbers
    for (int i = 0; i < N; ++i) {
        // Decrease K for each zero encountered
        if (lst[i] == 0) {
            K--;
        }
        // Add positive numbers to lst_p
        if (lst[i] > 0) {
            lst_p.push_back(lst[i]);
        }
        // Add negative numbers to lst_m
        else if (lst[i] < 0) {
            lst_m.push_back(lst[i]);
        }
    }

    // Initialize variables to track the last indices of positive and negative lists
    int lastx = lst_p.size();
    int lasty = lst_m.size();
    int ans = numeric_limits<int>::max(); // Initialize answer with a large number

    // Define a function to check the minimum value based on K
    for (int j = 0; j <= K; ++j) {
        // Check if the current count of positives and negatives is valid
        if (j > lastx || K - j > lasty) {
            continue; // Skip invalid combinations
        }

        // Determine the maximum positive number used
        int p = (j == 0) ? 0 : lst_p[j - 1]; // Get the largest positive number used

        // Determine the maximum negative number used
        int m = (K - j == 0) ? 0 : lst_m[lasty - (K - j)]; // Get the largest negative number used

        // Calculate the minimum value based on the current combination
        ans = min(ans, 2 * p + abs(m));
        ans = min(ans, p + 2 * abs(m));
    }

    // Print the result of the check function with K
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
