
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int n, m;
    string str;
    stringstream ss;
    string temp;
    string ans[100];

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> str;
        ss.str(str);
        temp = "";

        for (int j = 0; j < m; j++) {
            if (ss.peek() == '-') {
                temp += "-";
                ss.ignore();
            } else {
                if ((i + j) % 2 == 1) {
                    temp += "W";
                } else {
                    temp += "B";
                }
            }
        }

        ans[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

