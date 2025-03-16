
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> M(n);
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }

    int m = 0;

    for (int j = 0; j < n; j++) {
        int p = find(M.begin(), M.end(), 0) - M.begin();
        cout << p + 1 << " ";
        for (int l = 0; l < p + 1 - k; l++) {
            M[l]--;
        }
        M[p]--;
    }

    return 0;
}
