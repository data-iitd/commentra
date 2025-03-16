
#include <bits/stdc++.h>
using namespace std;

// Main function to solve the problem
int main() {
    // Read input string from the user
    string s;
    cin >> s;
    
    // Check if all characters in the string are the same
    if (count(s.begin(), s.end(), s[0]) == s.size()) {
        cout << 0 << endl;
        return 0;
    }
    
    // Count the frequency of each character in the string
    unordered_map<char, int> a;
    for (char c : s) {
        a[c]++;
    }
    
    // Calculate the answer as twice the minimum frequency of any character
    int ans = *min_element(a.begin(), a.end(), [](const pair<char, int>& p1, const pair<char, int>& p2) {
        return p1.second < p2.second;
    }).second * 2;
    
    // Print the answer and exit
    cout << ans << endl;
    
    return 0;
}

// Entry point of the script
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    main();
    
    return 0;
}

