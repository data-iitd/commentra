#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = regex_replace(s, regex("BC"), "D");
    long long cnt = 0;
    long long tmp = 0;
    for (char c : s) {
        if (c == 'A') {
            tmp++;
        } else if (c == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}

