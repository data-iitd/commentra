#include <iostream>
#include <vector>
#include <queue>
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
            if (0 <= y + dy[i] && y + dy[i] <= H - 1 && 0 <= x + dx[i] && x + dx[i] <= W - 1) {
                if (flag[y + dy[i]][x + dx[i]] == 0 && A[y + dy[i]][x + dx[i]] == '.') {
                    flag[y + dy[i]][x + dx[i]] = 1;
                    vector<int> queue_add = {y + dy[i], x + dx[i], depth + 1};
                    queue.push(queue_add);
                    ans = depth + 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

