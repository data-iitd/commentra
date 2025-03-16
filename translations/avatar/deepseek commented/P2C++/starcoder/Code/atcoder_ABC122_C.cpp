
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read the length of the string and the number of queries
    int n, q;
    cin >> n >> q;

    // Read the string
    string s;
    cin >> s;

    // Read the queries
    vector<vector<int>> problems(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> problems[i][0] >> problems[i][1];
    }

    // Define a function to count occurrences of 'AC' in the string
    int count(int total, int i) {
        // Check if the current substring is 'AC'
        if (s[i-1] == 'A' && s[i] == 'C') {
            // Increment the count if 'AC' is found
            return total + 1;
        } else {
            // Return the total count if 'AC' is not found
            return total;
        }
    }

    // Compute the cumulative sum of the list [0] + list(range(1, n)) using the count function
    vector<int> cumsum = accumulate(vector<int>({0}) + vector<int>(range(1, n)), count);

    // Iterate over the queries and print the difference in cumulative sums
    for (auto l, r : problems) {
        cout << cumsum[r-1] - cumsum[l-1] << endl;
    }

    return 0;
}

