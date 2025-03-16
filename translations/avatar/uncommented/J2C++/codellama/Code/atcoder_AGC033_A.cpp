#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    char A[H][W];
    queue<int*> queue;
    for (int i = 0; i < H; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < W; j++) {
            A[i][j] = row[j];
            if (A[i][j] == '#') {
                int* start = new int[3];
                start[0] = i;
                start[1] = j;
                start[2] = 0;
                queue.push(start);
            }
        }
    }
    int** flag = new int*[H];
    for (int i = 0; i < H; i++) {
        flag[i] = new int[W];
        memset(flag[i], 0, sizeof(int) * W);
    }
    int ans = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!queue.empty()) {
        int* temp = queue.front();
        queue.pop();
        int y = temp[0];
        int x = temp[1];
        int depth = temp[2];
        for (int i = 0; i < 4; i++) {
            if (0 <= y + dy[i] && y + dy[i] <= H - 1 && 0 <= x + dx[i] && x + dx[i] <= W - 1) {
                if (flag[y + dy[i]][x + dx[i]] == 0 && A[y + dy[i]][x + dx[i]] == '.') {
                    flag[y + dy[i]][x + dx[i]] = 1;
                    int* queue_add = new int[3];
                    queue_add[0] = y + dy[i];
                    queue_add[1] = x + dx[i];
                    queue_add[2] = depth + 1;
                    queue.push(queue_add);
                    ans = depth + 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

