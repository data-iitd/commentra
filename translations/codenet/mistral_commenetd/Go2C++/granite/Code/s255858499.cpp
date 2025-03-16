

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int a;
    ss >> a;

    getline(cin, line);
    stringstream ss2(line);
    int b;
    ss2 >> b;

    if (a * b % 2!= 0) {
        cout << "Odd" << endl;
    } else {
        cout << "Even" << endl;
    }

    return 0;
}

