#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 60;

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

// Function to read multiple integers from standard input
vector<int> ReadInts(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

// Function to read the initial dimensions and number of moves from standard input
tuple<int, int, int, int, int, int, int, int> ReadInput() {
    int H = ReadInt();
    int W = ReadInt();
    int K = ReadInt();
    int x1 = ReadInt() - 1;
    int y1 = ReadInt() - 1;
    int x2 = ReadInt() - 1;
    int y2 = ReadInt() - 1;
    return make_tuple(H, W, K, x1, y1, x2, y2);
}

// Function to read the input grid from standard input
vector<string> ReadGrid(int H, int W) {
    vector<string> c(H);
    for (int y = 0; y < H; y++) {
        cin >> c[y];
    }
    return c;
}

// Function to calculate the index of a cell in the grid based on its position and direction
int toID(int x, int y, int dir) {
    return 4 * (W * y + x) + dir;
}

// Function to extract the position and direction from the index of a cell
tuple<int, int, int> splatID(int id) {
    int x = id % W;
    int y = id / W;
    int dir = id % 4;
    return make_tuple(x, y, dir);
}

// Global variable to store the distance from the starting cell to all other cells
vector<long long> dist;

// Global variable to store the priority queue of states
priority_queue<tuple<long long, int, int, int>, vector<tuple<long long, int, int, int>>, greater<>> pq;

// Constant to represent infinity
const long long INF = 1LL << 60;

// Function to initialize the distances to infinity and add the starting cell to the priority queue
void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
    dist.resize(W * H * 4, INF);
    for (int i = 0; i < 4; i++) {
        pq.emplace(0, x1, y1, i);
    }
}

// Type to represent a state of the grid
struct State {
    long long cost;
    int x, y, dir;
};

// Function to process the priority queue until the goal cell is reached or all cells have been visited
void processPQ() {
    while (!pq.empty()) {
        auto [cost, x, y, dir] = pq.top();
        pq.pop();

        int id = toID(x, y, dir);
        if (dist[id] < cost) continue;

        dist[id] = cost;
        for (int i = 0; i < 4; i++) {
            int nCost = cost + K;
            int nID = toID(x, y, i);
            if (dist[nID] <= nCost) continue;
            pq.emplace(nCost, x, y, i);
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
            int nCost = cost + 1;
            int nID = toID(nx, ny, dir);
            if (dist[nID] <= nCost) continue;
            pq.emplace(nCost, nx, ny, dir);
        }
    }
}

// Function to calculate the minimum number of moves to reach the goal cell
long long calculateAnswer() {
    long long ans = INF;
    for (int i = 0; i < 4; i++) {
        int id = toID(x2, y2, i);
        ans = min(ans, dist[id]);
    }
    return ans;
}

// Function to print the result
void printResult(long long ans) {
    if (ans < INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}

// Constants to represent the possible directions of movement
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main() {
    // Read the input dimensions, number of moves, and starting and ending positions
    auto [H, W, K, x1, y1, x2, y2] = ReadInput();

    // Read the input grid
    vector<string> c = ReadGrid(H, W);

    // Initialize the distances and add the starting cell to the priority queue
    initDist(H, W, K, x1, y1, x2, y2);

    // Process the priority queue until the goal cell is reached or all cells have been visited
    processPQ();

    // Calculate the minimum number of moves to reach the goal cell
    long long ans = calculateAnswer();

    // Print the result
    printResult(ans);

    return 0;
}
