#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Hello World" << endl;
    } else {
        string s1, s2;
        cin >> s1 >> s2;
        cout << stoi(s1) + stoi(s2) << endl;
    }
    return 0;
}

