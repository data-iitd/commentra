
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string l;
    cin >> l;
    int i = l.find('.');
    string s = l.substr(0, i);
    string p = l.substr(i + 1);
    if (s[s.length() - 1] == '9') {
        cout << "GOTO Vasilisa." << endl;
    } else if (s[s.length() - 1]!= '9' && p[0] - '0' < 5) {
        cout << s << endl;
    } else {
        s[s.length() - 1]++;
        cout << s << endl;
    }
    return 0;
}

