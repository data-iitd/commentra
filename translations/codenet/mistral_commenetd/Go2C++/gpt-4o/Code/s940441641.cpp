#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

const long long Inf = numeric_limits<long long>::max();
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Function to read a single integer from standard input
int ReadInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read a single string from standard input
string ReadString() {
    string s;
    cin >> s;
    return s;
}

// Function to read the initial dimensions and number of moves from standard input
tuple<int, int, int, int, int, int, int, int> ReadInput() {
    int H = ReadInt(), W = ReadInt(), K = ReadInt();
    int x1 = ReadInt() - 1, y1 = ReadInt() - 1;
    int x2 = ReadInt() - 1, y2 = ReadInt() - 1;
    swap(x1, y1);
    swap(x2, y2);
    return {H, W, K, x1, y1, x2, y2};
}

// Function to read the input grid from standard input
vector<string> ReadGrid(int H, int W) {
    vector<string> grid(H);
    for (int y = 0; y < H; y++) {
        grid[y] = ReadString();
    }
    return grid;
}

// Function to calculate the index of a cell in the grid based on its position and direction
int toID(int x, int y, int dir, int W) {
    return 4 * (W * y + x) + dir;
}

// Function to extract the position and direction from the index of a cell
tuple<int, int, int> splatID(int id, int W) {
    int x = id % W;
    int y = id / W;
    int dir = id % 4;
    return {x, y, dir};
}

// Type to represent a state of the grid
struct State {
    long long Cost;
    int ID;
    bool operator>(const State& other) const {
        return Cost > other.Cost;
    }
};

int main() {
    // Read the input dimensions, number of moves, and starting and ending positions
    auto [H, W, K, x1, y1, x2, y2] = ReadInput();

    // Read the input grid
    vector<string> grid = ReadGrid(H, W);

    // Initialize the distances and the priority queue
    vector<long long> dist(W * H * 4, Inf);
    priority_queue<State, vector<State>, greater<State>> pq;

    // Add the starting cell to the priority queue
    for (int i = 0; i < 4; i++) {
        pq.push({0, toID(x1, y1, i, W)});
    }

    // Process the priority queue until the goal cell is reached or all cells have been visited
    while (!pq.empty()) {
        State now = pq.top();
        pq.pop();
        auto [x, y, dir] = splatID(now.ID, W);

        // If the current cell is the goal cell, break the loop
        if (x == x2 && y == y2) {
            break;
        }

        // If the current cell has already been visited, continue to the next cell
        if (dist[now.ID] <= now.Cost) {
            continue;
        }

        // Update the distance to the current cell
        dist[now.ID] = now.Cost;

        // Update the neighbors
        for (int i = 0; i < 4; i++) {
            long long nCost = now.Cost + K;
            int nID = toID(x, y, i, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            pq.push({nCost, nID});
        }

        // Move to the next neighbor
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            long long nCost = now.Cost + 1;
            int nID = toID(nx, ny, dir, W);
            if (dist[nID] <= nCost) {
                continue;
            }
            pq.push({nCost, nID});
        }
    }

    // Calculate the minimum number of moves to reach the goal cell
    long long ans = Inf;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i, W);
        if (dist[id] < ans) {
            ans = dist[id];
        }
    }

    // Print the result
    if (ans < Inf) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}

// <END-OF-CODE>
