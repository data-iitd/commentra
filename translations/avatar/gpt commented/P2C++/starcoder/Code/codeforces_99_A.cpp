#include <iostream>
#include <string>

using namespace std;

int main() {
    string l;
    cin >> l;
    string s = l.substr(0, l.find('.'));
    string p = l.substr(l.find('.') + 1);
    int i = p[0] - '0';
    if (s[s.size() - 1] == '9') {
        cout << "GOTO Vasilisa." << endl;
    } else if (s[s.size() - 1]!= '9' && i < 5) {
        cout << s << endl;
    } else {
        s = to_string(stoi(s) + 1);
        cout << s << endl;
    }
    return 0;
}
