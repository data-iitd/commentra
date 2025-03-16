#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    s = s.replace("dream", "D", -1);
    s = s.replace("erase", "E", -1);
    s = s.replace("Der", "");
    s = s.replace("Er", "");
    s = s.replace("D", "");
    s = s.replace("E", "");
    s = s.erase(0, s.find_first_not_of(' '));

    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

