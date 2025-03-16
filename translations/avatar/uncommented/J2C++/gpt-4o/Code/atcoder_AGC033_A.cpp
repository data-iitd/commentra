#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    queue<vector<int>> q;

    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j];
            if (A[i][j] == '#') {
                q.push({i, j, 0});
            }
        }
    }

    vector<vector<int>> flag(H, vector<int>(W, 0));
    int ans = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        vector<int> temp = q.front();
        q.pop();
        int y = temp[0];
        int x = temp[1];
        int depth = temp[2];

        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];
            if (0 <= newY && newY < H && 0 <= newX && newX < W) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    q.push({newY, newX, depth + 1});
                    ans = depth + 1;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

// <END-OF-CODE>
