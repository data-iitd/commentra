
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long i = 357;
    int c = 0;

    while (i <= N) {
        stringstream ss;
        ss << i;
        string s = ss.str();

        if (s.find('3')!= string::npos && s.find('5')!= string::npos && s.find('7')!= string::npos) {
            c++;
        }

        stringstream ss2;
        bool f = false;
        for (int j = s.length() - 1; j >= 0; j--) {
            char a = s[j];
            if (f) {
                ss2 << a;
            } else {
                if (a == '3') {
                    ss2 << '5';
                    f = true;
                } else if (a == '5') {
                    ss2 << '7';
                    f = true;
                } else {
                    ss2 << '3';
                }
            }
        }
        if (!f) {
            ss2 << '3';
        }
        string s2 = ss2.str();
        reverse(s2.begin(), s2.end());
        stringstream ss3(s2);
        ss3 >> i;
    }

    cout << c << endl;

    return 0;
}

