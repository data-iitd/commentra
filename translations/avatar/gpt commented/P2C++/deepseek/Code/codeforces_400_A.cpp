#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to read a single line of input and convert it to a tuple of integers
tuple<int, int, int> value() {
    int a, b, c;
    cin >> a >> b >> c;
    return make_tuple(a, b, c);
}

// Function to read a single line of input and return a list of integers
vector<int> inlst() {
    int n;
    cin >> n;
    vector<int> lst(n);
    for (int i = 0; i < n; ++i) {
        cin >> lst[i];
    }
    return lst;
}

// Function to read a single integer from input
int inp() {
    int n;
    cin >> n;
    return n;
}

// Function to read a single line of input and return it as a string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Helper function to determine if a specific arrangement is possible
bool help(const vector<int>& a, int b, int l) {
    vector<vector<int>> tot(b, vector<int>(l / b));
    // Create sublists of length 'b' from the list 'a'
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < l / b; ++j) {
            tot[i][j] = a[i * (l / b) + j];
        }
    }
    
    // Check if any combination of the sublists sums to 'b'
    for (int j = 0; j < l / b; ++j) {
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
    vector<int> tot;
    string x = instr();  // Read the input string
    vector<int> s;
    
    // Convert the input string into a list of integers (0 for 'O', 1 for 'X')
    for (char c : x) {
        if (c == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    
    // Check for all divisors of 12 to find valid arrangements
    for (int i = 1; i <= 12; ++i) {
        if (12 % i == 0) {  // Check if 'i' is a divisor of 12
            if (help(s, 12 / i, s.size())) {  // Use the helper function to check arrangements
                tot.push_back(12 / i);  // Store valid arrangements
                tot.push_back(i);  // Store valid arrangements
            }
        }
    }
    
    // Print the number of valid arrangements
    cout << tot.size() / 2 << " ";
    
    // Print each valid arrangement in sorted order
    sort(tot.begin(), tot.end());
    for (int i = 0; i < tot.size(); i += 2) {
        cout << tot[i] << "x" << tot[i + 1] << " ";
    }
    cout << endl;  // Print a newline at the end
}

int main() {
    // Read the number of test cases and solve each case
    int t = inp();
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

