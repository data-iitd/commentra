#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;
    for (int i = 0; i < n.length(); i++) {
        if (n[i] == '.') {
            if (i > 0 && n[i - 1] == '.') {
                cout << 1;
                s = false;
            } else {
                cout << 0;
            }
        } else {
            if (i > 0 && n[i - 1]!= '.') {
                cout << 2;
                s = false;
            } else {
                s = true;
            }
        }
    }
    return 0;
}

