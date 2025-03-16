#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to count occurrences of 'AC' in the string
int count(int total, const string& s, int i) {
    // Check if the current substring is 'AC'
    if (s.substr(i - 1, 2) == "AC") {
        // Increment the count if 'AC' is found
        return total + 1;
    } else {
        // Return the total count if 'AC' is not found
        return total;
    }
}

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    cin >> n >> q;

    // Read the string
    string s;
    cin >> s;

    // Read the queries
    vector<pair<int, int>> problems(q);
    for (int i = 0; i < q; ++i) {
        cin >> problems[i].first >> problems[i].second;
    }

    // Compute the cumulative sum
    vector<int> cumsum(n);
    cumsum[0] = 0; // Initialize the first element
    for (int i = 1; i < n; ++i) {
        cumsum[i] = count(cumsum[i - 1], s, i);
    }

    // Iterate over the queries and print the difference in cumulative sums
    for (const auto& p : problems) {
        int l = p.first, r = p.second;
        cout << cumsum[r - 1] - cumsum[l - 1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
