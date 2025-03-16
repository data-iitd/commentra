#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(4));

    for (int i = 0; i < n; i++) {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2] >> vec[i][3];
    }

    int ans = 500;
    int ansprice = 20000;

    for (int i = 0; i < n; i++) {
        bool fl = true;
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                fl = false;
                break;
            }
        }
        if (fl) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3];
                ans = i + 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
