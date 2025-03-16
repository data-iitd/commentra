#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<string> A(H);
    queue<vector<int>> queue;
    
    for (int i = 0; i < H; i++) {
        cin >> A[i];
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                vector<int> start = {i, j, 0};
                queue.push(start);
            }
        }
    }
    
    vector<vector<int>> flag(H, vector<int>(W, 0));
    int ans = 0;
    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    while (!queue.empty()) {
        vector<int> temp = queue.front();
        queue.pop();
        int y = temp[0];
        int x = temp[1];
        int depth = temp[2];
        
        for (int i = 0; i < 4; i++) {
            if (0 <= y + dy[i] && y + dy[i] < H && 0 <= x + dx[i] && x + dx[i] < W) {
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

