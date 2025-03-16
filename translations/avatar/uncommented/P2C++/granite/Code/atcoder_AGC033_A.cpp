
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> graph(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            graph[i][j] = (c == '#'? 0 : 100000000);
        }
    }
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            graph[y][x + 1] = min(graph[y][x + 1], graph[y][x] + 1);
        }
    }
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            graph[y][x - 1] = min(graph[y][x - 1], graph[y][x] + 1);
        }
    }
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            graph[y + 1][x] = min(graph[y + 1][x], graph[y][x] + 1);
        }
    }
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            graph[y - 1][x] = min(graph[y - 1][x], graph[y][x] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = max(ans, graph[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
