#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(); // To ignore the newline character after reading n and m
    vector<string> ans(n);

    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        string temp = "";

        for (int j = 0; j < m; j++) {
            if (str[j] == '-') {
                temp += "-";
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

// <END-OF-CODE>
