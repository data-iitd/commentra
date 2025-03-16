#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string run(string s, string t) {
    unordered_map<char, int> countS, countT;
    for (char c : s) {
        countS[c]++;
    }
    for (char c : t) {
        countT[c]++;
    }
    vector<int> ss, tt;
    for (auto& pair : countS) {
        ss.push_back(pair.second);
    }
    for (auto& pair : countT) {
        tt.push_back(pair.second);
    }
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if (ss == tt) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    cout << run(s, t) << endl;
    return 0;
}

