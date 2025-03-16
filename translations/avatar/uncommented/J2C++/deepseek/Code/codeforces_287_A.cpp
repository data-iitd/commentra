#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> str(4);
    for (int i = 0; i < 4; ++i) {
        cin >> str[i];
    }
    int yes = 0;
    for (int u = 0; u < 2; ++u) {
        for (int i = 0; i < 2; ++i) {
            if ((str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i])) ||
                (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))) {
                yes = 1;
                cout << "YES" << endl;
                break;
            }
        }
        if (yes == 1) {
            break;
        }
    }
    if (yes == 0) {
        cout << "NO" << endl;
    }
    return 0;
}

