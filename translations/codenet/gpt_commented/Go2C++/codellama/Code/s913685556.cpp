
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// Function to return the maximum of two integers
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

// Function to read a line from the input
string readLine() {
	string line;
	getline(cin, line);
	return line;
}

// Function to read a space-separated array of integers from the input
vector<int> readIntArray() {
	string line = readLine();
	stringstream ss(line);
	vector<int> result;
	int v;
	while (ss >> v) {
		result.push_back(v);
	}
	return result;
}

// Function to read a space-separated map of integers to booleans from the input
map<int, bool> readMap() {
	string line = readLine();
	stringstream ss(line);
	map<int, bool> mp;
	int v;
	while (ss >> v) {
		mp[v] = true;
	}
	return mp;
}

int main() {
	// Read two integers from input
	int A, B;
	cin >> A >> B;

	// Calculate the maximum of A+B, A-B, and A*B
	int mx = max(A+B, A-B);
	mx = max(mx, A*B);
	// Print the maximum value
	cout << mx << endl;
}

