#include <bits/stdc++.h>
using namespace std;

int main() {
    // Initialize an empty list's' by taking input from the user
    string s;
    cin >> s;

    // Create two dictionaries 'even' and 'odd' to count the frequency of '0' and '1' in the first and second half of the list's' respectively
    map<char, int> even, odd;
    for (int i = 0; i < s.length() / 2; i++) {
        even[s[i]]++;
    }
    for (int i = s.length() / 2; i < s.length(); i++) {
        odd[s[i]]++;
    }

    // Print the minimum difference between the length of the list's' and the sum of the frequencies of '0' and '1' in either half of the list
    cout << min(s.length() - (even['0'] + odd['1']), s.length() - (even['1'] + odd['0'])) << endl;

    return 0;
}

