#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string run(const string& s, const string& t) {
    // Count the frequency of each character in string s and sort the frequencies
    map<char, int> ss;
    for (char c : s) {
        ss[c]++;
    }
    vector<int> freqs_s;
    for (const auto& pair : ss) {
        freqs_s.push_back(pair.second);
    }
    sort(freqs_s.begin(), freqs_s.end());
    
    // Count the frequency of each character in string t and sort the frequencies
    map<char, int> tt;
    for (char c : t) {
        tt[c]++;
    }
    vector<int> freqs_t;
    for (const auto& pair : tt) {
        freqs_t.push_back(pair.second);
    }
    sort(freqs_t.begin(), freqs_t.end());
    
    // Compare the sorted frequency lists of both strings
    if (freqs_s == freqs_t) {
        return "Yes";  // Return 'Yes' if the frequency distributions are the same
    } else {
        return "No";   // Return 'No' if the frequency distributions are different
    }
}

int main() {
    // Read input strings s and t from the user
    string s, t;
    cin >> s >> t;
    
    // Print the result of the run function which checks the character frequency
    cout << run(s, t) << endl;

    return 0;
}
