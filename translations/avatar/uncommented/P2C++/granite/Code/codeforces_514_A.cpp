
#include <iostream>
#include <string>
using namespace std;

int main() {
    string ip;
    cin >> ip;
    string st = "";
    if (ip.length()!= 1) {
        if (ip[0] == '9') {
            st = "9";
            ip = ip.substr(1);
        }
        for (int i = 0; i < ip.length(); i++) {
            if (ip[i] - '0' > 4) {
                int n = 9 - (ip[i] - '0');
                st += to_string(n);
            } else {
                st += ip[i];
            }
        }
    } else {
        st = ip;
    }
    cout << stt << endl;
    return 0;
}
//END-OF-CODE