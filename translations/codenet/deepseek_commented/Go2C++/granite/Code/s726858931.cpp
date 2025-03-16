

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;

    char c = 'a';

    for (int j = 0; j < 26; j++) {
        bool found = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << c << endl;
            return 0;
        }
        c++;
    }

    cout << "None" << endl;

    return 0;
}

