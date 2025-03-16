
#include <iostream>
#include <string>

using namespace std;

int main() {
    string h1, m1, h2, m2;
    cin >> h1 >> m1;
    int m1_int = stoi(h1) * 60 + stoi(m1);
    cin >> h2 >> m2;
    int m2_int = stoi(h2) * 60 + stoi(m2);
    int diff = m1_int - m2_int;
    diff %= 1440;
    cout << (diff / 60) << ":" << (diff % 60) << endl;
    return 0;
}

