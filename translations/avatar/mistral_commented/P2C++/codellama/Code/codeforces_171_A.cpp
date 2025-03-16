#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int x = max(a.length(), b.length());
    a.insert(0, x - a.length(), '0');
    b.insert(0, x - b.length(), '0');

    string s = "";
    int c = 0;

    for (int i = 0; i < x; i++) {
        int d = b[i] - '0' + a[x - i - 1] - '0' + c;
        if (d > 9) {
            s += to_string(d)[1];
            c = 1;
        } else {
            s += to_string(d);
        }
    }

    if (c == 1) {
        s += "1";
    }

    s.erase(0, min(s.find_first_not_of('0'), s.size() - 1));
    cout << s << endl;

    return 0;
}

