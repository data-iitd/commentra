#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    // Read the number of characters in the string and the number of queries
    int n, q;
    cin >> n >> q;

    // Read the input string
    string s;
    cin >> s;

    // Read the queries, each containing two integers l and r
    vector<vector<int>> problems(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        problems[i] = {l, r};
    }

    // Define a function to count occurrences of 'AC' in the string
    auto count = [&](int total, int i) {
        // Increment total if the substring from index i-1 to i is 'AC'
        return total + 1 if s.substr(i - 1, 2) == "AC" else total;
    };

    // Create a cumulative sum list to keep track of 'AC' occurrences
    vector<int> cumsum(n + 1);
    cumsum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + count(0, i);
    }

    // Process each query to find the number of 'AC' occurrences in the specified range
    for (auto &problem : problems) {
        // Output the difference in cumulative sums to get the count in the range [l, r]
        cout << cumsum[problem[1] - 1] - cumsum[problem[0] - 1] << endl;
    }

    return 0;
}

