
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<string> s1s, s2s, s3s;
    s1s = split(s1);
    s2s = split(s2);
    s3s = split(s3);

    cout << toUpper(s1s[0]) + toUpper(s2s[0]) + toUpper(s3s[0]) << endl;

    return 0;
}

string toUpper(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

vector<string> split(string s) {
    vector<string> v;
    for (int i = 0; i < s.length(); i++) {
        v.push_back(s.substr(i, 1));
    }
    return v;
}

