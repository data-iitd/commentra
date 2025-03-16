#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to determine if a specific arrangement is possible
bool help(int a, int b, const vector<int>& l) {
    vector<vector<int>> tot(b);
    
    // Create sublists of length 'a' from the list 'l'
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) {
            tot[i].push_back(l[i * a + j]);
        }
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (int j = 0; j < a; ++j) {
        int sum = 0;
        for (int i = 0; i < b; ++i) {
            sum += tot[i][j];
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
void solve() {
    string x;
    cin >> x;  // Read the input string
    vector<int> s;
    
    // Convert the input string into a vector of integers (0 for 'O', 1 for 'X')
    for (char i : x) {
        if (i == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    
    vector<pair<int, int>> tot;
    
    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; ++i) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(i, 12 / i, s)) {  // Use the helper function to check arrangements
                tot.emplace_back(12 / i, i);  // Store valid arrangements as pairs
            }
        }
    }
    
    // Print the number of valid arrangements
    cout << tot.size() << ' ';
    
    // Print each valid arrangement in sorted order
    sort(tot.begin(), tot.end());
    for (const auto& p : tot) {
        cout << p.first << 'x' << p.second << ' ';
    }
    cout << endl;  // Print a newline at the end
}

// Entry point of the program
int main() {
    int t;
    cin >> t;  // Read the number of test cases
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
