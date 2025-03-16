
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), 'B'), s.end());
    s.erase(remove(s.begin(), s.end(), 'C'), s.end());
    s.insert(0, s.length(), 'D');
    long cnt = 0;
    long tmp = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            tmp++;
        } else if (s[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}
// The C++ code uses the erase() and insert() methods of the string class to replace all occurrences of "BC" with "D".

