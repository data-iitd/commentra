
#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 60; // Define a constant for infinity

int main() {
	// Read the dimensions of the grid and the cost parameter
	int H, W, K;
	cin >> H >> W >> K;
	// Read the starting and ending coordinates, adjusting for 0-based indexing
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--; y1--; x2--; y2--; // Adjust for 0-based indexing
	swap(x1, y1); // Swap x and y for the starting point
	swap(x2, y2); // Swap x and y for the ending point

	// Read the grid representation
	vector<string> c(H);
	for (int y = 0; y < H; y++) {
		cin >> c[y];
	}

	// Define movement directions (right, down, left, up)
	int dx[] = {1, 0, -1, 0};
	int dy[] = {0, 1, 0, -1};

	// Function to convert (x, y, dir) to a unique ID
	auto toID = [&](int x, int y, int dir) {
		return 4*(W*y+x) + dir;
	};
	// Function to convert an ID back to (x, y, dir)
	auto splatID = [&](int id) {
		return make_tuple(id / 4 % W, id / 4 / W, id % 4);
	};

	// Initialize the distance array with infinity
	vector<int> dist(W*H*4, INF);

	// Initialize the priority queue (min-heap) with starting states
	priority_queue<State, vector<State>, greater<State>> q;
	for (int i = 0; i < 4; i++) {
		q.push(State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		});
	}

	// Main loop for Dijkstra's algorithm
	while (!q.empty()) {
		State now = q.top(); // Get the state with the lowest cost
		q.pop();
		int x, y, dir;
		tie(x, y, dir) = splatID(now.ID); // Decompose the ID into coordinates and direction

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
			int nCost = (now.Cost + K - 1) / K * K; // Calculate the new cost
			int nID = toID(x, y, i); // Get the new ID for the direction
			if (dist[nID] <= nCost) { // Skip if we have a better cost
				continue;
			}
			// Push the new state into the priority queue
			q.push(State{
				Cost: nCost,
				ID:   nID,
			});
		}

		// Move in the current direction
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		// Check if the new position is within bounds
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1; // Increment the cost for moving forward
			int nID = toID(nx, ny, dir); // Get the new ID for the position
			if (dist[nID] <= nCost) { // Skip if we have a better cost
				continue;
			}
			// Push the new state into the priority queue
			q.push(State{
				Cost: nCost,
				ID:   nID,
			});
		}
	}

	// Determine the minimum cost to reach the destination
	int ans = INF;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i); // Get the ID for the destination in each direction
		if (dist[id] < ans) { // Check if we found a better cost
			int d2 = (dist[id] + K - 1) / K; // Calculate the cost in terms of K
			if (d2 < ans) { // Update the answer if it's better
				ans = d2;
			}
		}
	}

	// Output the result
	if (ans < INF) {
		cout << ans << endl; // Print the minimum cost
	} else {
		cout << -1 << endl; // Print -1 if the destination is unreachable
	}

	return 0;
}

// State represents a state in the priority queue with its cost and ID
struct State {
	int Cost, ID;
};

// Define the heap element type for the priority queue
using HeapElement = State;
using Heap = priority_queue<HeapElement, vector<HeapElement>, greater<HeapElement>>;

// Implement the heap interface for the custom heap type
bool operator<(const HeapElement& a, const HeapElement& b) {
	return a.Cost < b.Cost;
}

// Reader for standard input
istream& operator>>(istream& is, State& s) {
	is >> s.Cost >> s.ID;
	return is;
}

// Scan function to read input
void Scan(State& s) {
	cin >> s;
}

// ReadInt reads an integer from input
int ReadInt() {
	State s;
	Scan(s);
	return s.Cost;
}

// ReadString reads a string from input
string ReadString() {
	State s;
	Scan(s);
	return to_string(s.ID);
}

// ReadInts reads a slice of integers from input
vector<int> ReadInts(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		Scan(v[i]);
	}
	return v;
}

