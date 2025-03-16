
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int h1, m1;
    char c;
    ss >> h1 >> c >> m1;
    ss.clear();
    ss.str(string());
    getline(cin, s);
    ss << s;
    int h2, m2;
    ss >> h2 >> c >> m2;
    m2 += h2 * 60;
    m1 += h1 * 60;
    m2 = m1 - m2;
    m2 %= 1440;
    cout << setfill('0') << setw(2) << m2 / 60 << ":" << setfill('0') << setw(2) << m2 % 60 << endl;
    return 0;
}

