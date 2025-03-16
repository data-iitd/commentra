#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    istringstream iss(s);
    istringstream ist(t);
    int h1, m1, h2, m2;
    iss >> h1 >> m1;
    ist >> h2 >> m2;
    auto x = chrono::hours(h1) + chrono::minutes(m1);
    auto y = chrono::hours(h2) + chrono::minutes(m2);
    cout << x - y << endl;
    return 0;
}

