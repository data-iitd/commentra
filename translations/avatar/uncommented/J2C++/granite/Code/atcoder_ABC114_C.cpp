
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
        stringstream ss;
        ss << i;
        string s = ss.str();
        if (s.find("3")!= string::npos && s.find("5")!= string::npos && s.find("7")!= string::npos) {
            c++;
        }
        string t = "";
        bool f = false;
        for (int j = s.length() - 1; j >= 0; j--) {
            char a = s[j];
            if (f) {
                t += a;
            } else {
                if (a == '3') {
                    t += '5';
                    f = true;
                } else if (a == '5') {
                    t += '7';
                    f = true;
                } else {
                    t += '3';
                }
            }
        }
        if (!f) {
            t += '3';
        }
        reverse(t.begin(), t.end());
        stringstream ss2;
        ss2 << t;
        long long j;
        ss2 >> j;
        i = j;
    }
    cout << c << endl;
    return 0;
}
//END-OF-CODE