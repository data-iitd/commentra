#include <bits/stdc++.h>

using namespace std;

int main() {
	// Read an integer n from the standard input
	int n = nextInt();
	
	// Calculate the square root of n and store it in rt
	int rt = int(sqrt(n));
	
	// Initialize minf to 100, which will hold the minimum number of digits
	int minf = 100;
	
	// Iterate from 1 to rt + 1 to find divisors of n
	for (int i = 1; i < rt+1; i++) {
		if (n%i == 0) {
			// If i is a divisor of n, calculate the quotient b
			int b = n / i;
			
			// Count the number of digits in b
			int ndigit = 0;
			while (b > 0) {
				b /= 10;
				ndigit++;
			}
			
			// Update minf with the minimum number of digits found
			minf = min(minf, ndigit);
		}
	}
	
	// Print the minimum number of digits
	cout << minf << endl;
}

const int size = 1000000;

char buffer[size];
int position = 0;

// Read a line from the standard input
string nextLine() {
	if (position == 0) {
		fgets(buffer, size, stdin);
	}
	int begin = position;
	while (buffer[position]!= '\n' && buffer[position]!= '\0') {
		position++;
	}
	int end = position;
	position++;
	return string(buffer + begin, end - begin);
}

// Split the input line into a string array
vector<string> nextStringArray() {
	string line = nextLine();
	vector<string> strs;
	stringstream ss(line);
	string item;
	while (getline(ss, item,'')) {
		strs.push_back(item);
	}
	return strs;
}

// Read an integer from the standard input
int nextInt() {
	string line = nextLine();
	stringstream ss(line);
	int n;
	ss >> n;
	return n;
}

// Read an integer array from the standard input
vector<int> nextIntArray() {
	string line = nextLine();
	stringstream ss(line);
	vector<int> arr;
	int n;
	while (ss >> n) {
		arr.push_back(n);
	}
	return arr;
}

// Return the minimum of two integers
int min(int i, int j) {
	if (i > j) {
		return j;
	}
	return i;
}

