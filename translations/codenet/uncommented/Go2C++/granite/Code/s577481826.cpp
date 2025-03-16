
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int ret = stoi(a) + stoi(b);

    if (ret < (stoi(a) - stoi(b))) {
        ret = stoi(a) - stoi(b);
    }
    if (ret < (stoi(a) * stoi(b))) {
        ret = stoi(a) * stoi(b);
    }

    cout << ret << endl;

    return 0;
}

