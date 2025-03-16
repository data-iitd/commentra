#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long gi() {
    long long x;
    cin >> x;
    return x;
}

int main() {
    long long N = gi();
    long long i = 357;
    int c = 0;

    while (i <= N) {
        string s = to_string(i);
        if (s.find('3') != string::npos && s.find('5') != string::npos && s.find('7') != string::npos) {
            c++;
        }

        string sb;
        bool f = false;
        for (int j = 0; j < s.length(); j++) {
            char a = s[s.length() - 1 - j];
            if (f) {
                sb += a;
            } else {
                if (a == '3') {
                    sb += '5';
                    f = true;
                } else if (a == '5') {
                    sb += '7';
                    f = true;
                } else {
                    sb += '3';
                }
            }
        }
        if (!f) sb += '3';

        reverse(sb.begin(), sb.end());
        i = stoll(sb);
    }

    cout << c << endl;
    return 0;
}

// <END-OF-CODE>
