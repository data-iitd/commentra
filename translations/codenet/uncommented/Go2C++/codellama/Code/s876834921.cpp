#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    replace(s.begin(), s.end(), 'd', 'D');
    replace(s.begin(), s.end(), 'e', 'E');
    s.erase(remove(s.begin(), s.end(), 'D'), s.end());
    s.erase(remove(s.begin(), s.end(), 'E'), s.end());
    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    if (s.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

