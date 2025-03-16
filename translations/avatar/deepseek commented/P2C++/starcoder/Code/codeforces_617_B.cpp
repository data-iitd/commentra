
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a;
    cin >> a;
    if (a.find("1") == string::npos) {
        cout << 0 << endl;
    } else {
        vector<string> b = split(a, "1");
        int c = 1;
        for (int i = 0; i < b.size(); i++) {
            c *= (b[i].size() + 1);
        }
        cout << c << endl;
    }
    return 0;
}

string split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start))!= string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

