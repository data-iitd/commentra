#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    ans += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (isLatinLetter(s[i]) &&!isLatinLetter(s[i - 1])) {
            ans +='';
        }
        ans += s[i];
    }
    cout << ans << endl;
    return 0;
}

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

