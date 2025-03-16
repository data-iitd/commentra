#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long i = 357;
    int c = 0;

    while (i <= N) {
        string s = to_string(i);

        if (s.find('3') != string::npos && s.find('5') != string::npos && s.find('7') != string::npos) {
            c++;
        }

        stringstream sb;
        bool f = false;

        for (int j = s.length() - 1; j >= 0; j--) {
            char a = s[j];

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
                    f = true;
                }
            }
        }

        if (!f) sb << '3';

        string reversed = sb.str();
        reverse(reversed.begin(), reversed.end());
        i = stoll(reversed);
    }

    cout << c << endl;

    return 0;
}

