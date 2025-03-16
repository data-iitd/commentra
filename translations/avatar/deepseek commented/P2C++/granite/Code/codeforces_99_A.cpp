

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string l;
    cin >> l;
    vector<string> l_split = {"", ""};
    int i = 0;
    for (char c : l) {
        if (c == '.') {
            i++;
        } else {
            l_split[i] += c;
        }
    }
    vector<char> s(l_split[0].begin(), l_split[0].end());
    vector<char> p(l_split[1].begin(), l_split[1].end());
    int j = p[0] - '0';
    if (s[s.size() - 1] == '9') {
        cout << "GOTO Vasilisa." << endl;
    } else if (s[s.size() - 1]!= '9' && j < 5) {
        string s_str = "";
        for (char c : s) {
            s_str += c;
        }
        cout << s_str << endl;
    } else {
        string s_str = "";
        for (char c : s) {
            s_str += c;
        }
        int k = stoi(s_str) + 1;
        cout << k << endl;
    }
    return 0;
}

