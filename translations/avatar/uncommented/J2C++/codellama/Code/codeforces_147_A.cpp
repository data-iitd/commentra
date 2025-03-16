
#include <iostream>
#include <string>
using namespace std;

bool isLatinLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPunctuation(char c) {
    if (c == '.') return true;
    if (c == ',') return true;
    if (c == '!') return true;
    if (c == '?') return true;
    return false;
}

int main() {
    string s;
    getline(cin, s);
    string sb;
    int n = s.length();
    sb.push_back(s[0]);
    for (int i = 1; i < n; i++) {
        char c = s[i];
        if (isLatinLetter(c)) {
            if (!isLatinLetter(s[i - 1])) {
                sb.push_back(' ');
            }
            sb.push_back(c);
        } else if (isPunctuation(c)) {
            sb.push_back(c);
        }
    }
    cout << sb << endl;
    return 0;
}

