
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int x = max(a.length(), b.length());
    a = string(x - a.length(), '0') + a;
    b = string(x - b.length(), '0') + b;
    string s = "";
    int c = 0;
    for (int i = x - 1; i >= 0; i--) {
        int d = (b[i] - '0') + (a[i] - '0') + c;
        if (d >= 10) {
            s += (d % 10) + '0';
            c = 1;
        } else {
            s += d + '0';
            c = 0;
        }
    }
    if (c == 1) s += '1';
    reverse(s.begin(), s.end());
    cout << stoi(s) << endl;
    return 0;
}

