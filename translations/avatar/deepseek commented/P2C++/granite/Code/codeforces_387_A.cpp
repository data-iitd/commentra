

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int h1 = stoi(s1.substr(0, 2));
    int m1 = stoi(s1.substr(3, 2));
    int h2 = stoi(s2.substr(0, 2));
    int m2 = stoi(s2.substr(3, 2));

    m1 += h1 * 60;
    m2 += h2 * 60;

    int m3 = m1 - m2;
    if (m3 < 0) m3 += 1440;

    cout << setfill('0') << setw(2) << m3 / 60 << ":" << setfill('0') << setw(2) << m3 % 60 << endl;

    return 0;
}

