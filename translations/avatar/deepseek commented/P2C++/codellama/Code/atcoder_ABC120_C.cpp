#include <bits/stdc++.h>
using namespace std;

// Main function to solve the problem
int main() {
    // Read input string from the user
    string s;
    cin >> s;
    
    // Check if all characters in the string are the same
    if (s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    // Count the frequency of each character in the string
    map<char, int> a;
    for (char c : s) {
        a[c]++;
    }
    
    // Calculate the answer as twice the minimum frequency of any character
    int ans = INT_MAX;
    for (auto it : a) {
        ans = min(ans, it.second * 2);
    }
    
    // Print the answer and exit
    cout << ans << endl;
    return 0;
}

// End of code
