#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    string result = "";
    int i = 0;
    cin >> s;
    while (i < s.length()) {
        if (s[i] == '.') {
            result += '0';
        } else {
            i++;
            if (i < s.length() && s[i] == '.') {
                result += '1';
            } else {
                result += '2';
            }
        }
        i++;
    }
    cout << result << endl;
    return 0;
}

