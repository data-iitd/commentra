#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// Function to count occurrences of 'AC' in the string
int count(int total, const string& s, int i) {
    // Increment total if the substring from index i-1 to i is 'AC'
    return total + (s.substr(i - 1, 2) == "AC" ? 1 : 0);
}

int main() {
    // Read the number of characters in the string and the number of queries
    int n, q;
    cin >> n >> q;

    // Read the input string
    string s;
    cin >> s;

    // Read the queries, each containing two integers l and r
    vector<pair<int, int>> problems(q);
    for (int i = 0; i < q; ++i) {
        cin >> problems[i].first >> problems[i].second;
    }

    // Create a cumulative sum vector to keep track of 'AC' occurrences
    vector<int> cumsum(n);
    cumsum[0] = 0; // Initialize the first element

    // Fill the cumulative sum vector
    for (int i = 1; i < n; ++i) {
        cumsum[i] = count(cumsum[i - 1], s, i);
    }

    // Process each query to find the number of 'AC' occurrences in the specified range
    for (const auto& [l, r] : problems) {
        // Output the difference in cumulative sums to get the count in the range [l, r]
        cout << cumsum[r - 1] - cumsum[l - 1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
