
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = replace(s.begin(), s.end(), "dream", "D");
    s = replace(s.begin(), s.end(), "erase", "E");
    s = replace(s.begin(), s.end(), "Der", "");
    s = replace(s.begin(), s.end(), "Er", "");
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    if (s == "") {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

