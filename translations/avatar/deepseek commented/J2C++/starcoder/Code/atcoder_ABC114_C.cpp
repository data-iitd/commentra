#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long i = 357;
    int c = 0;

    while (i <= N) {
        string s = to_string(i);
        if (s.find("3")!= string::npos && s.find("5")!= string::npos && s.find("7")!= string::npos) {
            c++;
        }

        string s2 = "";
        bool f = false;
        for (int j = 0; j < s.length(); j++) {
            char a = s[s.length() - 1 - j];
            if (f) {
                s2 += a;
            } else {
                if (a == '3') {
                    s2 += '5';
                    f = true;
                } else if (a == '5') {
                    s2 += '7';
                    f = true;
                } else {
                    s2 += '3';
                }
            }
        }
        if (!f) s2 += '3';

        string s3 = s2;
        reverse(s3.begin(), s3.end());
        i = stoll(s3);
    }

    cout << c << "\n";
}

