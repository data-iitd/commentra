#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    // Step 1: Reading the Input
    string s;
    cin >> s;

    // Step 2: Calculating the Size of the String
    int n = s.size();

    // Step 3: Initializing an Array to Count Character Frequencies
    int v[26] = {};

    // Step 4: Counting Character Frequencies
    for (int i = 0; i < n; i++) {
        v[s[i] - 'a']++;
    }

    // Step 5: Determining the Result
    string ans = "Yes";
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 != 0) {
            ans = "No";
            break;
        }
    }

    // Step 6: Outputting the Result
    cout << ans << endl;
}
