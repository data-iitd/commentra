#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int gi() {
    int x;
    cin >> x;
    return x;
}

long gl() {
    long x;
    cin >> x;
    return x;
}

int main() {
    int N = gi();
    long i = 357;
    int c = 0;

    while (i <= N) {
        string s = to_string(i);
        if (s.find('3') != string::npos && s.find('5') != string::npos && s.find('7') != string::npos) {
            c++;
        }

        stringstream sb;
        bool f = false;
        for (int j = 0; j < s.length(); j++) {
            char a = s[s.length() - 1 - j];
            if (f) {
                sb << a;
            } else {
                if (a == '3') {
                    sb << '5';
                    f = true;
                } else if (a == '5') {
                    sb << '7';
                    f = true;
                } else {
                    sb << '3';
                }
            }
        }
        if (!f) sb << '3';

        string sb_str = sb.str();
        reverse(sb_str.begin(), sb_str.end());
        i = stol(sb_str);
    }

    cout << c << endl;
    return 0;
}
