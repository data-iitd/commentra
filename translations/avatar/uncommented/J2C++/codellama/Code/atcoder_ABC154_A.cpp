
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str[3];
    int a, b;
    string u;
    cin >> str[0] >> str[1] >> str[2] >> a >> b >> u;
    if (u == str[0]) {
        cout << a - 1 << " " << b << endl;
    } else {
        cout << a << " " << b - 1 << endl;
    }
    return 0;
}

