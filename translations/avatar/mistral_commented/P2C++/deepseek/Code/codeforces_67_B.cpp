#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> M(n);
    for (int i = 0; i < n; ++i) {
        cin >> M[i];
    }

    int m = 0;

    for (int j = 0; j < n; ++j) {
        for (int p = 0; p < n; ++p) {
            if (M[p] == 0) {
                cout << p + 1 << " ";
                break;
            }
        }
        for (int l = 0; l < p + 1 - k; ++l) {
            M[l] -= 1;
        }
        M[p] -= 1;
    }

    cout << endl;
    return 0;
}

