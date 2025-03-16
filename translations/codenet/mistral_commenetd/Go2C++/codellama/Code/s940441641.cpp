
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to read a single integer from standard input
int ReadInt() {
	int i;
	scanf("%d", &i);
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
		scanf("%d", &v[i]);
	}
	return v;
}

// Function to read the initial dimensions and number of moves from standard input
tuple<int, int, int, int, int, int, int, int> ReadInput() {
	int H, W, K;
	int x1, y1, x2, y2;
	scanf("%d %d %d", &H, &W, &K);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	swap(x1, y1);
	swap(x2, y2);
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

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
	dist = vector<int>(W * H * 4, Inf);
	for (int i = 0; i < 4; i++) {
		q.push(State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		});
	}
}

// Function to process the heap until the goal cell is reached or all cells have been visited
void processHeap() {
	while (!q.empty()) {
		State now = q.top();
		q.pop();
		int x, y, dir;
		tie(x, y, dir) = splatID(now.ID);

		if (x == x2 && y == y2) {
			break;
		}

		if (dist[now.ID] <= now.Cost) {
			continue;
		}

		dist[now.ID] = now.Cost;
		for (int i = 0; i < 4; i++) {
			int nCost = now.Cost + K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			});
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			});
		}
	}
}

// Function to calculate the minimum number of moves to reach the goal cell
int calculateAnswer() {
	int ans = Inf;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			ans = dist[id];
		}
	}
	return ans;
}

// Function to print the result
void printResult() {
	if (ans < Inf) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
}

// Global variables
vector<int> dist;
priority_queue<State> q;
const int Inf = 1 << 60;

// Constants
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Types
struct State {
	int Cost, ID;
};

// Functions
void Scan(int &a) {
	scanf("%d", &a);
}

void Scan(string &a) {
	cin >> a;
}

void Scan(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		scanf("%d", &a[i]);
	}
}

void Scan(tuple<int, int, int, int, int, int, int, int> &a) {
	int H, W, K;
	int x1, y1, x2, y2;
	scanf("%d %d %d", &H, &W, &K);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	swap(x1, y1);
	swap(x2, y2);
	a = make_tuple(H, W, K, x1, y1, x2, y2);
}

void Scan(vector<string> &a) {
	for (int y = 0; y < a.size(); y++) {
		cin >> a[y];
	}
}

int main() {
	// Read the input dimensions, number of moves, and starting and ending positions
	int H, W, K, x1, y1, x2, y2;
	tie(H, W, K, x1, y1, x2, y2) = ReadInput();

	// Read the input grid
	vector<string> c = ReadGrid(H, W);

	// Initialize the distances and add the starting cell to the heap
	initDist(H, W, K, x1, y1, x2, y2);

	// Process the heap until the goal cell is reached or all cells have been visited
	processHeap();

	// Calculate the minimum number of moves to reach the goal cell
	ans = calculateAnswer();

	// Print the result
	printResult();

	return 0;
}

// Comments
// Function to read a single integer from standard input
// Returns an integer value read from standard input
int ReadInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a single string from standard input
// Returns a string value read from standard input
string ReadString() {
	string s;
	cin >> s;
	return s;
}

// Function to read multiple integers from standard input
// Reads n integers from standard input and returns a vector of integers
vector<int> ReadInts(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	return v;
}

// Function to read the initial dimensions and number of moves from standard input
// Returns the height, width, and number of moves of the grid
tuple<int, int, int, int, int, int, int, int> ReadInput() {
	int H, W, K;
	int x1, y1, x2, y2;
	scanf("%d %d %d", &H, &W, &K);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	swap(x1, y1);
	swap(x2, y2);
	return make_tuple(H, W, K, x1, y1, x2, y2);
}

// Function to read the input grid from standard input
// Returns a vector of strings representing the grid
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

// Function to initialize the distances to all cells to infinity and add the starting cell to the heap
void initDist(int H, int W, int K, int x1, int y1, int x2, int y2) {
	dist = vector<int>(W * H * 4, Inf);
	for (int i = 0; i < 4; i++) {
		q.push(State{
			Cost: 0,
			ID:   toID(x1, y1, i),
		});
	}
}

// Function to process the heap until the goal cell is reached or all cells have been visited
void processHeap() {
	while (!q.empty()) {
		State now = q.top();
		q.pop();
		int x, y, dir;
		tie(x, y, dir) = splatID(now.ID);

		if (x == x2 && y == y2) {
			break;
		}

		if (dist[now.ID] <= now.Cost) {
			continue;
		}

		dist[now.ID] = now.Cost;
		for (int i = 0; i < 4; i++) {
			int nCost = now.Cost + K;
			int nID = toID(x, y, i);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			});
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (0 <= nx && nx < W && 0 <= ny && ny < H) {
			int nCost = now.Cost + 1;
			int nID = toID(nx, ny, dir);
			if (dist[nID] <= nCost) {
				continue;
			}
			q.push(State{
				Cost: nCost,
				ID:   nID,
			});
		}
	}
}

// Function to calculate the minimum number of moves to reach the goal cell
int calculateAnswer() {
	int ans = Inf;
	for (int i = 0; i < 4; i++) {
		int id = toID(x2, y2, i);
		if (dist[id] < ans) {
			ans = dist[id];
		}
	}
	return ans;
}

// Function to print the result
void printResult() {
	if (ans < Inf) {
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
}

// Global variables
vector<int> dist;
priority_queue<State> q;
const int Inf = 1 << 60;

// Constants
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Types
struct State {
	int Cost, ID;
};

// Functions
void Scan(int &a) {
	scanf("%d", &a);
}

void Scan(string &a) {
	cin >> a;
}

void Scan(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		scanf("%d", &a[i]);
	}
}

void Scan(tuple<int, int, int, int, int, int, int, int> &a) {
	int H, W, K;
	int x1, y1, x2, y2;
	scanf("%d %d %d", &H, &W, &K);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	x1--;
	y1--;
	x2--;
	y2--;
	swap(x1, y1);
	swap(x2, y2);
	a = make_tuple(H, W, K, x1, y1, x2, y2);
}

void Scan(vector<string> &a) {
	for (int y = 0; y < a.size(); y++) {
		cin >> a[y];
	}
}

int main() {
	// Read the input dimensions, number of moves, and starting and ending positions
	int H, W, K, x1, y1, x2, y2;
	tie(H, W, K, x1, y1, x2, y2) = ReadInput();

	// Read the input grid
	vector<string> c = ReadGrid(H, W);

	// Initialize the distances and add the starting cell to the heap
	initDist(H, W, K, x1, y1, x2, y2);

	// Process the heap until the goal cell is reached or all cells have been visited
	processHeap();

	// Calculate the minimum number of moves to reach the goal cell
	ans = calculateAnswer();

	// Print the result
	printResult();

	return 0;
}

// Comments
// Function to read a single integer from standard input
// Returns an integer value read from standard input
int ReadInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a single string from standard input
// Returns a string value read from standard input
string ReadString() {
	string s;
	cin >> s;
	return s;
}

// Function to read multiple integers from standard input
// Reads n integers from standard input and returns a vector of integers
vector<int> ReadInts(int n) {
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
