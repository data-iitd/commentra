
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

    int ret = a + b;

    if (ret < (a - b)) {
        ret = a - b;
    }
    if (ret < (a * b)) {
        ret = a * b;
    }

    cout << ret << endl;

    return 0;
}

