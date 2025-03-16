#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string run(string s, string t) {
    // Count the frequency of each character in string s and sort the frequencies
    map<char, int> ss;
    for (int i = 0; i < s.length(); i++) {
        ss[s[i]]++;
    }
    vector<int> v;
    for (auto it = ss.begin(); it != ss.end(); it++) {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end());
    
    // Count the frequency of each character in string t and sort the frequencies
    map<char, int> tt;
    for (int i = 0; i < t.length(); i++) {
        tt[t[i]]++;
    }
    vector<int> w;
    for (auto it = tt.begin(); it != tt.end(); it++) {
        w.push_back(it->second);
    }
    sort(w.begin(), w.end());
    
    // Compare the sorted frequency lists of both strings
    if (v == w) {
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

