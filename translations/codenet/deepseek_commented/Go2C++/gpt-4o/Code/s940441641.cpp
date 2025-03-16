#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const long long Inf = numeric_limits<long long>::max();

struct State {
    long long Cost;
    int ID;
    bool operator>(const State& other) const {
        return Cost > other.Cost;
    }
};

int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int& x, int& y, int& dir, int W) {
    x = (id / 4) % W;
    y = (id / 4) / W;
    dir = id % 4;
}

int main() {
    int H, W, K;
    cin >> H >> W >> K; // Reading the dimensions of the grid and the number of obstacles.
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2; // Reading the starting and ending coordinates.
    x1--; y1--; x2--; y2--; // Adjusting for 0-based indexing.
    swap(x1, y1); // Adjusting the coordinates for the grid's indexing.
    swap(x2, y2); // Adjusting the coordinates for the grid's indexing.

    vector<string> c(H); // Creating a vector to hold the grid rows.
    for (int y = 0; y < H; y++) {
        cin >> c[y]; // Reading each row of the grid.
    }

    vector<int> dx = {1, 0, -1, 0}; // Defining the possible horizontal directions.
    vector<int> dy = {0, 1, 0, -1}; // Defining the possible vertical directions.

    vector<long long> dist(W * H * 4, Inf); // Initializing the distance array.

    priority_queue<State, vector<State>, greater<State>> q; // Initializing the priority queue.
    for (int i = 0; i < 4; i++) {
        q.push({0, toID(x1, y1, i, W)}); // Starting from all possible directions at the initial position.
    }

    while (!q.empty()) { // Processing each state in the priority queue.
        State now = q.top(); q.pop(); // Getting the state with the minimum cost.
        int x, y, dir;
        splatID(now.ID, x, y, dir, W); // Splitting the ID back into coordinates and direction.

        if (c[y][x] == '@') continue; // Skipping if the current cell is an obstacle.
        if (dist[now.ID] <= now.Cost) continue; // Skipping if the current cost is not the minimum.
        dist[now.ID] = now.Cost; // Updating the minimum cost to reach this state.
        if (x == x2 && y == y2) break; // Breaking if the end is reached.

        for (int i = 0; i < 4; i++) { // Considering all possible directions.
            long long nCost = (now.Cost + K - 1) / K * K; // Calculating the cost to the next state.
            int nID = toID(x, y, i, W); // Getting the ID of the next state.
            if (dist[nID] <= nCost) continue; // Skipping if the next state has been processed with a lower cost.
            q.push({nCost, nID}); // Pushing the next state into the priority queue.
        }

        int nx = x + dx[dir]; // Calculating the next x-coordinate.
        int ny = y + dy[dir]; // Calculating the next y-coordinate.
        if (0 <= nx && nx < W && 0 <= ny && ny < H) { // Checking if the next position is within the grid.
            long long nCost = now.Cost + 1; // Calculating the cost to move to the next position.
            int nID = toID(nx, ny, dir, W); // Getting the ID of the next position.
            if (dist[nID] <= nCost) continue; // Skipping if the next position has been processed with a lower cost.
            q.push({nCost, nID}); // Pushing the next position into the priority queue.
        }
    }

    long long ans = Inf; // Initializing the answer with infinity.
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W); // Getting the ID of the end position from each direction.
        if (dist[id] < ans) { // Updating the answer if a new minimum cost is found.
            long long d2 = (dist[id] + K - 1) / K; // Calculating the minimum number of obstacles to overcome.
            if (d2 < ans) {
                ans = d2;
            }
        }
    }

    if (ans < Inf) { // Outputting the result.
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
