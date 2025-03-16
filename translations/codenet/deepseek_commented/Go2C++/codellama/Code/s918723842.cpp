
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

// Scanner struct to read input efficiently.
struct Scanner {
	char* buf;
	int p;
	int buf_size;
	
	Scanner() {
		buf_size = 1000;
		buf = new char[buf_size];
		p = 0;
	}
	
	void pre() {
		if (p >= buf_size) {
			readLine();
			p = 0;
		}
	}
	
	void readLine() {
		char* new_buf = new char[buf_size * 2];
		memcpy(new_buf, buf, buf_size);
		delete[] buf;
		buf = new_buf;
		buf_size *= 2;
		
		int i = 0;
		while (true) {
			char c = getchar();
			if (c == '\n' || c == '\0') {
				buf[i] = '\0';
				break;
			}
			buf[i] = c;
			i++;
		}
	}
	
	char* next() {
		pre();
		char* start = buf + p;
		while (buf[p] != ' ' && buf[p] != '\0') {
			p++;
		}
		char* result = new char[p - start + 1];
		memcpy(result, start, p - start);
		result[p - start] = '\0';
		p++;
		return result;
	}
	
	char* nextLine() {
		pre();
		char* start = buf + p;
		p = buf_size;
		return start;
	}
	
	int nextInt() {
		return atoi(next());
	}
	
	long long nextInt64() {
		return atoll(next());
	}
	
	double nextFloat() {
		return atof(next());
	}
	
	int* nextIntArray() {
		pre();
		int* result = new int[buf_size];
		int i = 0;
		int start = p;
		while (buf[p] != '\0') {
			if (buf[p] == ' ') {
				result[i] = atoi(buf + start);
				start = p + 1;
				i++;
			}
			p++;
		}
		result[i] = atoi(buf + start);
		return result;
	}
	
	long long* nextInt64Array() {
		pre();
		long long* result = new long long[buf_size];
		int i = 0;
		int start = p;
		while (buf[p] != '\0') {
			if (buf[p] == ' ') {
				result[i] = atoll(buf + start);
				start = p + 1;
				i++;
			}
			p++;
		}
		result[i] = atoll(buf + start);
		return result;
	}
	
	bool* nextMap() {
		pre();
		bool* result = new bool[buf_size];
		int i = 0;
		int start = p;
		while (buf[p] != '\0') {
			if (buf[p] == ' ') {
				result[atoi(buf + start)] = true;
				start = p + 1;
				i++;
			}
			p++;
		}
		result[atoi(buf + start)] = true;
		return result;
	}
};

// Initializes a new Scanner instance to read from standard input.
Scanner sc = Scanner();

// Reads three integers H, W, and N from the standard input.
int H, W, N;
H = sc.nextInt();
W = sc.nextInt();
N = sc.nextInt();

// Determines the maximum of H and W and assigns it to A.
int A = max(H, W);

// Calculates the result by dividing N by A and rounding up.
// This is done by adding N-1 to the division result and then performing integer division by A.
printf("%d\n", (N + A - 1) / A);

// Returns the maximum of two integers.
int max(int a, int b) {
	if (a < b) {
		return b;
	}
	return a;
}

