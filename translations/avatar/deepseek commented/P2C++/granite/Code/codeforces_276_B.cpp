
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;  // Read the input string
    map<char, int> dt;  // Initialize an empty map to store character frequencies
    bool x = true;  // Initialize a boolean variable to track the result
    int cnt = 0;  // Initialize a counter to keep track of characters with an odd frequency

    // Iterate over each character in the input string and update the frequency count in the map
    for (int i = 0; i < s.length(); i++) {
        if (dt.find(s[i])!= dt.end()) {
            dt[s[i]]++;
        } else {
            dt[s[i]] = 1;
        }
    }

    // Iterate over the items in the map to determine if there is more than one character with an odd frequency
    for (auto it = dt.begin(); it!= dt.end(); it++) {
        if (it->second % 2!= 0 && cnt < 1) {
            cnt++;
        } else if (it->second % 2!= 0 && cnt >= 1) {
            x = false;
            break;
        }
    }

    // Determine the output based on the value of cnt and the length of the input string
    if (x) {
        cout << "First" << endl;  // Print "First" if there is at most one character with an odd frequency
    } else if (!x && s.length() % 2 == 0) {
        cout << "Second" << endl;  // Print "Second" if there is more than one character with an odd frequency and the length of the input string is even
    } else if (!x && s.length() % 2!= 0) {
        cout << "First" << endl;  // Print "First" if there is more than one character with an odd frequency and the length of the input string is odd
    }

    return 0;
}
