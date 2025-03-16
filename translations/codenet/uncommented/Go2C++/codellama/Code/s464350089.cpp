
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cctype>
using namespace std;

const int mod = 1000000007;

// 1MB
const int ioBufferSize = 1 * 1024 * 1024;
char ioBuffer[ioBufferSize];
char *ioBufferPtr = ioBuffer;
char *ioBufferEnd = ioBuffer + ioBufferSize;

char *next() {
	if (ioBufferPtr == ioBufferEnd) {
		ioBufferPtr = ioBuffer;
		fread(ioBuffer, 1, ioBufferSize, stdin);
	}
	return ioBufferPtr++;
}

int nextInt() {
	char c;
	int val = 0;
	while ((c = *next()) < '0') {
	}
	while (c >= '0') {
		val = val * 10 + c - '0';
		c = *next();
	}
	return val;
}

int main() {
	int h, n;
	h = nextInt();
	n = nextInt();
	int a = 0;

	for (int i = 0; i < n; i++) {
		a += nextInt();
	}

	if (h > a) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}
}

