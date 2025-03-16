
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

const int mod = 1000000007;

// 1MB
const int ioBufferSize = 1 * 1024 * 1024;
char ioBuffer[ioBufferSize];

// Read the initial height `h` and the number of attacks `n`
int h, n;

// Initialize a variable to keep track of the total damage dealt
int a = 0;

// Read each attack's damage and accumulate the total damage
for (int i = 0; i < n; i++) {
	a += nextInt();
}

// Check if the total damage is greater than or equal to the initial height
if (h > a) {
	cout << "No" << endl;
} else {
	cout << "Yes" << endl;
}

// Read the next integer
int nextInt() {
	int result = 0;
	char c;
	do {
		c = getchar();
	} while (c < '0' || c > '9');
	do {
		result = result * 10 + c - '0';
		c = getchar();
	} while (c >= '0' && c <= '9');
	return result;
}

