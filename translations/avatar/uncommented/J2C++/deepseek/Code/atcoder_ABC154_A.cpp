#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    string str[2];
    ss >> str[0] >> str[1];

    int a, b;
    getline(cin, line);
    stringstream st(line);
    st >> a >> b;

    getline(cin, line);
    if (line == str[0]) {
        cout << (a - 1) << " " << b << endl;
    } else {
        cout << a << " " << (b - 1) << endl;
    }

    return 0;
}
