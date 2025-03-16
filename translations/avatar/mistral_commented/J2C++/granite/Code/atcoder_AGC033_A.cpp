

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W));
    queue<vector<int>> queue;

    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j];
            if (A[i][j] == '#') {
                vector<int> start = {i, j, 0};
                queue.push(start);
            }
        }
    }

    vector<vector<int>> flag(H, vector<int>(W, 0));
    int ans = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    while (!queue.empty()) {
        vector<int> temp = queue.front();
        queue.pop();
        int y = temp[0];
        int x = temp[1];
        int depth = temp[2];

        for (int i = 0; i < 4; i++) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            if (0 <= newY && newY <= H - 1 && 0 <= newX && newX <= W - 1) {
                if (flag[newY][newX] == 0 && A[newY][newX] == '.') {
                    flag[newY][newX] = 1;
                    vector<int> queue_add = {newY, newX, depth + 1};
                    queue.push(queue_add);
                    ans = max(ans, depth + 1);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

