
// C++ code to find the first character missing from a given string
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    sort(alphabet.begin(), alphabet.end());

    for (char c : alphabet) {
        if (s.find(c) == string::npos) {
            cout << c << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}

