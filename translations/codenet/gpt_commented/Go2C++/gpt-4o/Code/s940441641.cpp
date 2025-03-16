#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

const long long Inf = numeric_limits<long long>::max(); // Define a constant for infinity

struct State {
    long long Cost;
    int ID;
    bool operator>(const State& other) const {
        return Cost > other.Cost; // For min-heap
    }
};

int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

void splatID(int id, int& x, int& y, int& dir, int W) {
    x = id / 4 % W;
    y = id / 4 / W;
    dir = id % 4;
}

int main() {
    // Read the dimensions of the grid and the cost parameter
    int H, W, K;
    cin >> H >> W >> K;

    // Read the starting and ending coordinates, adjusting for 0-based indexing
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--; // Convert to 0-based indexing
    swap(x1, y1); // Swap x and y for the starting point
    swap(x2, y2); // Swap x and y for the ending point

    // Read the grid representation
    vector<string> c(H);
    for (int y = 0; y < H; y++) {
        cin >> c[y];
    }

    // Define movement directions (right, down, left, up)
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    // Initialize the distance array with infinity
    vector<long long> dist(W * H * 4, Inf);

    // Initialize the priority queue (min-heap) with starting states
    priority_queue<State, vector<State>, greater<State>> q;
    for (int i = 0; i < 4; i++) {
        q.push(State{0, toID(x1, y1, i, W)});
    }

    // Main loop for Dijkstra's algorithm
    while (!q.empty()) {
        State now = q.top(); q.pop(); // Get the state with the lowest cost
        int x, y, dir;
        splatID(now.ID, x, y, dir, W); // Decompose the ID into coordinates and direction

        // Skip if the current position is a wall
        if (c[y][x] == '@') {
            continue;
        }
        // Skip if we have already found a better cost for this state
        if (dist[now.ID] <= now.Cost) {
            continue;
        }
        // Update the distance for the current state
        dist[now.ID] = now.Cost;

        // If we reached the destination, exit the loop
        if (x == x2 && y == y2) {
            break;
        }

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            long long nCost = (now.Cost + K - 1) / K * K; // Calculate the new cost
            int nID = toID(x, y, i, W); // Get the new ID for the direction
            if (dist[nID] <= nCost) { // Skip if we have a better cost
                continue;
            }
            // Push the new state into the priority queue
            q.push(State{nCost, nID});
        }

        // Move in the current direction
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        // Check if the new position is within bounds
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            long long nCost = now.Cost + 1; // Increment the cost for moving forward
            int nID = toID(nx, ny, dir, W); // Get the new ID for the position
            if (dist[nID] <= nCost) { // Skip if we have a better cost
                continue;
            }
            // Push the new state into the priority queue
            q.push(State{nCost, nID});
        }
    }

    // Determine the minimum cost to reach the destination
    long long ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W); // Get the ID for the destination in each direction
        if (dist[id] < ans) { // Check if we found a better cost
            long long d2 = (dist[id] + K - 1) / K; // Calculate the cost in terms of K
            if (d2 < ans) { // Update the answer if it's better
                ans = d2;
            }
        }
    }

    // Output the result
    if (ans < Inf) {
        cout << ans << endl; // Print the minimum cost
    } else {
        cout << -1 << endl; // Print -1 if the destination is unreachable
    }

    return 0;
}

// <END-OF-CODE>
