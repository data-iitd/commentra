#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, A, B;
    cin >> H >> W >> A >> B;

    if (W < 2 * A || H < 2 * B) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i < B && j < A) || (i >= B) && (j >= A)) {
                cout << "0";
            } else {
                cout << "1";
            }
        }
        cout << "\n";
    }

    return 0;
}

