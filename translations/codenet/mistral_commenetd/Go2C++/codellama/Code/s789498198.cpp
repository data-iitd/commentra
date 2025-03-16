
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Initialize scanner and read the first line
void init() {
	sc.buf.clear();
	sc.cur = 0;
	string line;
	getline(cin, line);
	stringstream ss(line);
	string temp;
	while (ss >> temp) {
		sc.buf.push_back(temp);
	}
}

// scanner type definition
struct scanner {
	vector<string> buf;
	int cur;
};

// Function to read a line
void readln(scanner &s) {
	s.buf.clear();
	string line;
	getline(cin, line);
	stringstream ss(line);
	string temp;
	while (ss >> temp) {
		s.buf.push_back(temp);
	}
	s.cur = 0;
}

// Function to check if the scanner is full
bool isFull(scanner &s) {
	if (s.cur == s.buf.size()) {
		return true;
	}
	return false;
}

// Function to reset the current index
void resetCur(scanner &s) {
	s.cur = 0;
}

// Function to read next string
string next(scanner &s) {
	if (s.cur == 0) {
		readln(s);
	}
	string res = s.buf[s.cur];
	s.cur++;
	if (isFull(s)) {
		resetCur(s);
	}
	return res;
}

// Function to read next integers
vector<int> nextInts(scanner &s) {
	readln(s);
	vector<int> res;
	for (int i = 0; i < s.buf.size(); i++) {
		res.push_back(stoi(s.buf[i]));
	}
	resetCur(s);
	return res;
}

// Function to calculate the number of digits in an integer
int digits(int x) {
	return to_string(x).length();
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
void varDump(int value) {
	cout << value << endl;
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
void Push(Queue &q, Pair v) {
	q.v.push_back(v);
}

// Function to pop a pair from the queue
Pair Pop(Queue &q) {
	Pair r = q.v[0];
	q.v.erase(q.v.begin());
	return r;
}

// Function to get the front pair from the queue
Pair Front(Queue &q) {
	return q.v[0];
}

// Function to check if the queue is empty
bool Empty(Queue &q) {
	return q.v.empty();
}

// Main function
int main() {
	// Initialize scanner and read the first line
	scanner sc;
	init();

	// Read the first two integers from the input
	vector<int> AB = nextInts(sc);
	int A = AB[0];
	int B = AB[1];

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

