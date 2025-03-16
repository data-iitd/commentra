
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Take input from the user
    cin.ignore();
    // Read the input, split it into a list of integers, and store it in 'a'
    vector<int> a;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        a.push_back(s[i] - '0');
    }
    // Sort the list 'a'
    sort(a.begin(), a.end());
    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < a.size(); i++) {
        // Check if the current element is not equal to the previous element
        // and if the current element is less than twice the previous element
        if (a[i]!= a[i - 1] && a[i] < a[i - 1] * 2) {
            // If the condition is met, return 'YES'
            return cout << "YES" << endl, 0;
        }
    }
    // If the loop completes without finding a match, return 'NO'
    return cout << "NO" << endl, 0;
}
// Print the result returned by the function's()'
// 