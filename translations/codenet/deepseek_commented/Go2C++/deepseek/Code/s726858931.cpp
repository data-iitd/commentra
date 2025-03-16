#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (char c = 'a'; c <= 'z'; ++c) {
        bool found = false;
        for (char ch : s) {
            if (ch == c) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << c << endl;
            return 0;
        }
    }

    cout << "None" << endl;
    return 0;
}

