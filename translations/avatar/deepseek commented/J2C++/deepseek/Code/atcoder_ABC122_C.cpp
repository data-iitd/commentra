#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1000000007;

int main() {
    // Create a Scanner object to read input
    int n, q;
    cin >> n >> q;

    // Read the string as a character array
    string s;
    cin >> s;

    // Read the ranges for the queries and store them in a 2D vector
    vector<vector<int>> range(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> range[i][0] >> range[i][1];
    }

    // Initialize arrays to count "AC" fragments and store cumulative sums
    vector<int> frag(n + 1, 0);
    vector<int> rui(n + 1, 0);

    // Process the string to find "AC" fragments
    for (int i = 2; i <= n; i++) {
        if (s[i - 2] == 'A' && s[i - 1] == 'C') {
            // Increment the count of "AC" fragments at position i
            frag[i]++;
        }
        // Update the cumulative sum array
        rui[i] = rui[i - 1] + frag[i];
    }

    // Process the queries
    for (int i = 0; i < q; i++) {
        int left = range[i][0];
        int right = range[i][1];
        // Calculate the number of "AC" fragments in the given range
        cout << rui[right] - rui[left] << endl;
    }

