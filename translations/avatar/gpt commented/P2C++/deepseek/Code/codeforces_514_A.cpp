#include <iostream>
#include <string>
using namespace std;

int main() {
    string ip;
    cin >> ip;

    string st = "";

    if (ip.length() != 1) {
        if (ip[0] == '9') {
            st = "9";
            ip = ip.substr(1);
        }

        for (char i : ip) {
            if (i - '0' > 4) {
                int n = 9 - (i - '0');
                st += to_string(n);
            } else {
                st += i;
            }
        }
    } else {
        st = ip;
    }

    cout << stoi(st) << endl;

    return 0;
}

