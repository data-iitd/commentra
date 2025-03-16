
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), 'B'), s.end());
    s.erase(remove(s.begin(), s.end(), 'C'), s.end());
    s.insert(0, s.length(), 'D');
    cout << s << endl;
    return 0;
}

