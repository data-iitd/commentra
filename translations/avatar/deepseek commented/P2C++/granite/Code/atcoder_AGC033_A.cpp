

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<int>> graph(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            graph[i][j] = (s[j] == '#'? 0 : 100000000);
        }
    }

    // Calculate the minimum distance to any '#' for each cell in the grid
    // Processing in the left to right direction
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h; y++) {
            graph[y][x + 1] = min(graph[y][x] + 1, graph[y][x + 1]);
        }
    }

    // Processing in the right to left direction
    for (int x = w - 1; x > 0; x--) {
        for (int y = 0; y < h; y++) {
            graph[y][x - 1] = min(graph[y][x] + 1, graph[y][x - 1]);
        }
    }

    // Processing in the top to bottom direction
    for (int y = 0; y < h - 1; y++) {
        for (int x = 0; x < w; x++) {
            graph[y + 1][x] = min(graph[y][x] + 1, graph[y + 1][x]);
        }
    }

    // Processing in the bottom to top direction
    for (int y = h - 1; y > 0; y--) {
        for (int x = 0; x < w; x++) {
            graph[y - 1][x] = min(graph[y][x] + 1, graph[y - 1][x]);
        }
    }

    // Print the maximum value in the graph, which represents the maximum distance to the nearest '#'
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans = max(ans, graph[i][j]);
        }
    }
    cout << ans << endl;

    return 0;
}
