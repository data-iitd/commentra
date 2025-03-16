
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;
    vector<string> a = { "10", "100", "1000", "10000", "100000" };
    int new = 0;
    for (char c : n) {
        new += c - '0';
    }
    if (find(a.begin(), a.end(), n)!= a.end()) {
        cout << 10 << endl;
    } else {
        cout << new << endl;
    }
    return 0;
}

END-OF-CODE