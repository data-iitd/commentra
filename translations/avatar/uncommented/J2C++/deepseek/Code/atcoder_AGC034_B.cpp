#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    string t = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B' && i + 1 < s.length() && s[i + 1] == 'C') {
            t += 'D';
            i++;
        } else {
            t += s[i];
        }
    }
    long long cnt = 0;
    long long tmp = 0;
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == 'A') {
            tmp++;
        } else if (t[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
