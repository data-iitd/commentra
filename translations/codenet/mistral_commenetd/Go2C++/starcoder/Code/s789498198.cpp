#include <bits/stdc++.h>

using namespace std;

// Initialize scanner and read the first line
void init() {
	sc = scanner{
		buf: make([]string, 0, 0),
		cur: 0,
		r:   cin.tie(0),
	};
	sc.readln(); // Read the first line
}

// Main function
int main() {
	// Read the first two integers from the input
	int A, B;
	cin >> A >> B;

	// Check if the sum of A and B is even
	if ((A + B) % 2 == 0) {
		// If it is, print the result (the average)
		cout << (A + B) / 2 << endl;
		return 0;
	}
	// If the sum is odd, print "IMPOSSIBLE"
	cout << "IMPOSSIBLE" << endl;
	return 0;
}

// scanner type definition
struct scanner {
	vector<string> buf;
	int cur;
	istream *r;
};

// Function to read a line
void readln() {
	string rbuf;
	getline(*r, rbuf);
	cur = 0;
	buf = split(rbuf, " ");
}

// Function to check if the scanner is full
bool isFull() {
	if (cur == buf.size()) {
		return true;
	}
	return false;
}

// Function to reset the current index
void resetCur() {
	cur = 0;
}

// Function to read next string
string next() {
	if (cur == 0) {
		readln();
	}
	string res = buf[cur];
	cur++;
	if (isFull()) {
		resetCur();
	}
	return res;
}

// Function to read next integers
vector<int> nextInts() {
	readln();
	vector<int> res(buf.size());
	for (int i = 0; i < buf.size(); i++) {
		res[i] = atoi(buf[i].c_str());
	}
	resetCur();
	return res;
}

// Function to calculate the number of digits in an integer
int digits(int x) {
	return to_string(x).size();
}

// Function to calculate the power of a number
int powInt(int x, int p) {
	int result = 1;
	for (int i = 0; i < p; i++) {
		result *= x;
	}
	return result;
}

// Function to find the maximum of two integers
int max(int x, int y) {
	return max(x, y);
}

// Function to find the minimum of two integers
int min(int x, int y) {
	return min(x, y);
}

// Function to calculate the absolute value of an integer
int abs(int x) {
	return abs(x);
}

// Function to print the values of variables
void varDump(const vector<int> &value) {
	for (int i = 0; i < value.size(); i++) {
		cout << value[i] << endl;
	}
}

// Function to print "Yes"
void yes() {
	cout << "Yes" << endl;
}

// Function to print "No"
void no() {
	cout << "No" << endl;
}

// Pair type definition
struct Pair {
	int first;
	int second;
};

// Queue type definition
struct Queue {
	vector<Pair> v;
};

// Function to push a pair into the queue
void push(Queue &q, Pair v) {
	q.v.push_back(v);
}

// Function to pop a pair from the queue
Pair pop(Queue &q) {
	Pair r = q.v[0];
	q.v = q.v.erase(q.v.begin() + 1);
	return r;
}

// Function to get the front pair from the queue
Pair front(Queue q) {
	return q.v[0];
}

// Function to check if the queue is empty
bool empty(Queue q) {
	return q.v.size() == 0;
}

// 