
#include <bits/stdc++.h>

using namespace std;

// I/O
class Scanner {
public:
	Scanner() : buf(new char[1 << 17]), curChar(0), curPos(0) {
		scanf(" %s", buf);
	}

	char nextChar() {
		if (curPos == strlen(buf)) {
			curPos = 0;
			scanf(" %s", buf);
		}
		curChar = buf[curPos++];
		return curChar;
	}

	int nextInt() {
		int x = 0;
		bool neg = false;
		char c = nextChar();
		while (c <= 32) {
			c = nextChar();
		}
		if (c == '-') {
			neg = true;
			c = nextChar();
		}
		for (x = 0; c > 32; c = nextChar()) {
			x = x*10 + c - '0';
		}
		if (neg) {
			return -x;
		}
		return x;
	}

private:
	char *buf;
	int curChar, curPos;
};

// Arithmetic
int max(int a, int b) {
	return a > b? a : b;
}

int min(int a, int b) {
	return a < b? a : b;
}

int abs(int x) {
	return x < 0? -x : x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

int ceil(int a, int b) {
	return (a + b - 1) / b;
}

// Sort
struct RuneSlice {
	vector<int> v;
	RuneSlice() {}
	RuneSlice(const vector<int> &v) : v(v) {}
	int Len() { return v.size(); }
	bool Less(int i, int j) { return v[i] < v[j]; }
	void Swap(int i, int j) { swap(v[i], v[j]); }
};

// Main
const int MOD = int(1e+9) + 7; // Modulus value for modular arithmetic
const int INF = 1 << 60;      // Infinite value for comparison

// Mon represents a monster with x-coordinate and height
struct Mon {
	int x, h;
};

// Mons is a slice of Mon structures
typedef vector<Mon> Mons;

// Node represents a node in the priority queue with x-coordinate and damage
struct Node {
	int x, h;
};

// Queue is a priority queue implemented as a slice with custom push, pop, and isEmpty functions
struct Queue {
	vector<Node> arr;
	void push(Node v) {
		arr.push_back(v);
	}
	Node first() {
		return arr[0];
	}
	Node pop() {
		Node res = arr[0];
		arr = arr[1:];
		return res;
	}
	bool isEmpty() {
		return arr.size() == 0;
	}
};

int main() {
	// Initialize a new Scanner and a bufio.Writer for input/output
	Scanner sc;
	bufio::Writer wtr(cout.rdbuf());

	// Read input values N, D, and A from the scanner
	int N, D, A = sc.nextInt(), sc.nextInt(), sc.nextInt();

	// Initialize a vector of Mon structures called M
	Mons M;

	// Read x and h values for each Mon and store them in the M vector
	for (int i = 0; i < N; i++) {
		M.push_back(Mon{sc.nextInt(), sc.nextInt()});
	}

	// Sort the M vector based on x-coordinates
	sort(M.begin(), M.end(), [](Mon a, Mon b) { return a.x < b.x; });

	// Initialize an empty priority queue called q
	Queue q;

	// Initialize answer variable ans to 0 and total variable total to 0
	int ans = 0;
	int total = 0;

	// Iterate through each Mon in the sorted M vector
	for (int i = 0; i < N; i++) {
		// Current Mon
		Mon m = M[i];

		// While the priority queue is not empty and the current Mon's x-coordinate is smaller than the x-coordinate of the first Node in the priority queue
		while (!q.isEmpty() && q.first().x < m.x) {
			// Pop the first Node from the priority queue
			total -= q.pop().h;
		}

		// If the total damage is less than the Mon's height, calculate the remaining damage, add it to the answer, and push it to the priority queue
		if (total < m.h) {
			int damage = m.h - total;
			ans += damage;
			q.push(Node{m.x + 2*D, damage});
			total += damage;
		}
	}

	// Print the answer
	printf("%d\n", ans);

	// Flush the writer to output the answer
	wtr.flush();
}

