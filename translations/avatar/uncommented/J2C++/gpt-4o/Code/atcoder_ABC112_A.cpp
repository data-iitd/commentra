#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after reading n

    if (n == 1) {
        cout << "Hello World" << endl;
    } else {
        vector<string> strs(2);
        for (int i = 0; i < 2; i++) {
            getline(cin, strs[i]);
        }
        int sum = stoi(strs[0]) + stoi(strs[1]);
        cout << sum << endl;
    }

    return 0;
}

// <END-OF-CODE>
