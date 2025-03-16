
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s.find("A") != string::npos && s.find("B") != string::npos) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

// END-OF-CODE
