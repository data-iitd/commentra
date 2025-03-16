
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    cin >> n >> q;

    // Read the string
    string s;
    cin >> s;

    // Read the queries
    vector<vector<int>> problems(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        problems[i] = {l, r};
    }

    // Define a function to count occurrences of 'AC' in the string
    auto count = [&](int total, int i) {
        // Check if the current substring is 'AC'
        if (s.substr(i-1, 2) == "AC") {
            // Increment the count if 'AC' is found
            return total + 1;
        } else {
            // Return the total count if 'AC' is not found
            return total;
        }
    };

    // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
    vector<int> cumsum = {0};
    for (int i = 1; i <= n; i++) {
        cumsum.push_back(count(cumsum[i-1], i));
    }

    // Iterate over the queries and print the difference in cumulative sums
    for (auto &problem : problems) {
        int l = problem[0], r = problem[1];
        cout << cumsum[r-1] - cumsum[l-1] << endl;
    }

    return 0;
}

