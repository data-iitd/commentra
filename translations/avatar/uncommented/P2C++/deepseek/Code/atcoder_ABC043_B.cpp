#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string my_str;
    cin >> s;
    for (char c : s) {
        if (c == '0' || c == '1') {
            my_str += c;
        } else if (c == 'B' && !my_str.empty()) {
            my_str.pop_back();
        }
    }
    cout << my_str << endl;
    return 0;
}

