
```cpp
#include <bits/stdc++.h>
using namespace std;

// Global variables to store counts and the result
vector<int> a; // Vector to hold counts of specific characters
int ans = 0; // Variable to hold the final answer

// Depth-first search function to calculate combinations
void dfs(int left, int i, int res) {
    // If no more characters left to choose, add the result to ans
    if (left == 0) {
        ans += res;
        return;
    }
    // Iterate through the vector starting from index i
    for (int j = i; j < a.size(); j++) {
        // Recursive call to dfs with one less character to choose
        dfs(left - 1, j + 1, res * a[j]);
    }
}

int main() {
    // Initialize input reader
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // Read the number of characters
    int n;
    cin >> n;
    // Map to count occurrences of specific characters
    map<char, int> dic;

    // Read n characters and count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c; // Read the first character of the string
        switch (c) {
            case 'M':
            case 'A':
            case 'R':
            case 'C':
            case 'H':
                dic[c]++; // Increment count for the character if it's one of the specified
                break;
        }
    }

    // Populate the vector a with the counts from the dictionary
    for (auto const &[key, value] : dic) {
        a.push_back(value);
    }

    // Start the DFS to calculate the product of combinations of 3 characters
    dfs(3, 0, 1);
    // Print the final result
    cout << ans << endl;
    return 0;
}

