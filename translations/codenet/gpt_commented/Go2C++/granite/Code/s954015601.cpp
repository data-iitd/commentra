
// 深さ優先探索
#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

// genid generates a unique identifier for an edge between two nodes a and b
// by ensuring a is less than b and combining them into a single integer.
int genid(int a, int b) {
	if (b < a) {
		a = b;
		b = a;
	}
	return a * 100000 + b;
}

int main() {
	// Read the number of nodes in the graph
	int N;
	cin >> N;

	// Initialize a vector to hold the edges and a vector of vectors for the adjacency list
	vector<pair<int, int>> ab(N - 1);
	vector<vector<int>> edges(N);

	// Read edges from input and populate the adjacency list
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; // Convert to zero-based index
		b--; // Convert to zero-based index
		ab[i] = make_pair(a, b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// Map to store colors assigned to edges
	map<int, int> colors;
	// Stack for depth-first search (DFS) with current node, used color, and parent node
	stack<tuple<int, int, int>> q;
	q.push(make_tuple(0, -1, -1)); // Start DFS from node 0 with no used color and no parent

	// Perform DFS to assign colors to edges
	while (!q.empty()) {
		int currentNode, usedColor, parentNode;
		tie(currentNode, usedColor, parentNode) = q.top();
		q.pop();
		int color = 1; // Start coloring from color 1

		// Iterate through child nodes of the current node
		for (int childNode : edges[currentNode]) {
			if (childNode == parentNode) {
				continue; // Skip the parent node to avoid backtracking
			}
			if (color == usedColor) {
				color++; // Skip the color that was used by the parent
			}
			// Assign color to the edge between currentNode and childNode
			colors[genid(currentNode, childNode)] = color;
			// Push the child node onto the stack for further exploration
			q.push(make_tuple(childNode, color, currentNode));
			color++; // Move to the next color for the next edge
		}
	}

	// Find the maximum degree of any node in the graph
	int K = -1;
	for (int i = 0; i < N; i++) {
		int t = edges[i].size(); // Degree of the current node
		if (t > K) {
			K = t; // Update maximum degree if current node's degree is greater
		}
	}
	cout << K << endl; // Print the maximum degree

	// Print the colors assigned to each edge
	for (int i = 0; i < N - 1; i++) {
		cout << colors[genid(ab[i].first, ab[i].second)] << endl;
	}
}

// Constants for input buffer size
const int ioBufferSize = 1 * 1024 * 1024; // 1 MB

// cinbuf reads input from standard input and handles any buffering issues
char cinbuf[ioBufferSize];
size_t cinbufIndex = ioBufferSize;
char getChar() {
	if (cinbufIndex == ioBufferSize) {
		cin.read(cinbuf, ioBufferSize);
		cinbufIndex = 0;
	}
	return cinbuf[cinbufIndex++];
}

// Read a string from standard input
string readString() {
	string result;
	char c = getChar();
	while (c =='') {
		c = getChar();
	}
	while (c!='' && c!= '\n') {
		result += c;
		c = getChar();
	}
	return result;
}

// Read an integer from standard input and handle any conversion errors
int readInt() {
	int result = 0;
	bool isNegative = false;
	char c = getChar();
	while (c =='') {
		c = getChar();
	}
	if (c == '-') {
		isNegative = true;
		c = getChar();
	}
	while (c >= '0' && c <= '9') {
		result = 10 * result + (c - '0');
		c = getChar();
	}
	if (isNegative) {
		result = -result;
	}
	return result;
}

// Translate the above C++ code to Java and end with comment "