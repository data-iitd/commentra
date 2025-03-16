#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// Function to count the number of 'AC' substrings
int countAC(const string& s, int total, int i) {
    return (s.substr(i - 1, 2) == "AC") ? total + 1 : total;
}

int main() {
    // Taking input for number of strings 'n' and number of problems 'q'
    int n, q;
    cin >> n >> q;

    // Taking input for the string 's'
    string s;
    cin >> s;

    // List to store the start and end indices of each problem
    vector<pair<int, int>> problems(q);
    for (int i = 0; i < q; ++i) {
        cin >> problems[i].first >> problems[i].second;
    }

    // Vector to store cumulative sums of 'AC' substrings
    vector<int> cumsum(n);
    cumsum[0] = 0; // Initial value for cumulative sum

    // Calculate cumulative sums
    for (int i = 1; i < n; ++i) {
        cumsum[i] = countAC(s, cumsum[i - 1], i);
    }

    // Iterating through each problem and printing the difference in cumulative sums
    for (const auto& problem : problems) {
        int l = problem.first;
        int r = problem.second;
        cout << cumsum[r - 1] - cumsum[l - 1] << endl;
    }

    return 0;
}

// <END-OF-CODE>
