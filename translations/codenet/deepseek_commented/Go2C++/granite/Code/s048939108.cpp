

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;
    if (S.substr(0, 5) == "YAKI") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

