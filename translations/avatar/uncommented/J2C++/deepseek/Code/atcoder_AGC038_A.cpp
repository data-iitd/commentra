#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    if (W < 2 * A || H < 2 * B) {
        cout << -1 << endl;
        return 0;
    }
    vector<string> grid(H, string(W, ' '));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if ((i < B && j < A) || (i >= B && j >= A)) {
                grid[i][j] = '0';
            } else {
                grid[i][j] = '1';
            }
        }
    }
    for (const auto& row : grid) {
        cout << row << endl;
    }
    return 0;
}

