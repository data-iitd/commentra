#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Global variables
vector<int> a; // a stores the counts of characters 'M', 'A', 'R', 'C', 'H'
int ans = 0;   // ans accumulates the result of the calculations performed by the dfs function

// dfs is a recursive function that calculates the product of 3 elements from vector a
void dfs(int left, int i, int res) {
    if (left == 0) {
        ans += res; // When no elements are left to multiply, add the result to ans
        return;
    }
    for (int j = i; j < a.size(); j++) {
        dfs(left - 1, j + 1, res * a[j]); // Recursively call dfs with updated parameters
    }
}

// main function to execute the program
int main() {
    int n;
    cin >> n; // Read the number of characters
    unordered_map<char, int> dic;

    // Count occurrences of 'M', 'A', 'R', 'C', 'H'
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'M' || c == 'A' || c == 'R' || c == 'C' || c == 'H') {
            dic[c]++;
        }
    }

    // Append the counts of 'M', 'A', 'R', 'C', 'H' to vector a
    for (const auto& v : dic) {
        a.push_back(v.second);
    }

    // Call dfs with parameters 3, 0, and 1
    dfs(3, 0, 1);
    cout << ans << endl; // Print the final result

    return 0;
}

// <END-OF-CODE>
