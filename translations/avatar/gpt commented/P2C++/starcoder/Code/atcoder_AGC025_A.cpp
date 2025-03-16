#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string n;
    cin >> n;

    vector<string> a = {"10", "100", "1000", "10000", "100000"};

    int new = 0;
    for (int i = 0; i < n.length(); i++) {
        new += (int)n[i] - 48;
    }

    if (n == "10" || n == "100" || n == "1000" || n == "10000" || n == "100000") {
        cout << "10" << endl;
    } else {
        cout << new << endl;
    }

    return 0;
}

