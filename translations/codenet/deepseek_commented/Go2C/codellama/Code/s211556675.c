#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// I/O
typedef struct Scanner {
	char* buf;
	int buf_size;
	int buf_pos;
	FILE* fp;
} Scanner;

Scanner* NewScanner() {
	Scanner* sc = (Scanner*)malloc(sizeof(Scanner));
	sc->buf_size = 1024;
	sc->buf_pos = 0;
	sc->fp = stdin;
	sc->buf = (char*)malloc(sc->buf_size);
	return sc;
}

char* nextStr(Scanner* sc) {
	char* res = (char*)malloc(1024);
	fscanf(sc->fp, "%s", res);
	return res;
}

int nextInt(Scanner* sc) {
	int res;
	fscanf(sc->fp, "%d", &res);
	return res;
}

float nextFloat(Scanner* sc) {
	float res;
	fscanf(sc->fp, "%f", &res);
	return res;
}

char* nextRuneSlice(Scanner* sc) {
	char* res = (char*)malloc(1024);
	fscanf(sc->fp, "%s", res);
	return res;
}

int* nextIntSlice(Scanner* sc, int n) {
	int* res = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		fscanf(sc->fp, "%d", &res[i]);
	}
	return res;
}

float* nextFloatSlice(Scanner* sc, int n) {
	float* res = (float*)malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++) {
		fscanf(sc->fp, "%f", &res[i]);
	}
	return res;
}

// Arithmetic
int max(int nums[], int n) {
	int m = nums[0];
	for (int i = 1; i < n; i++) {
		if (m < nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

int min(int nums[], int n) {
	int m = nums[0];
	for (int i = 1; i < n; i++) {
		if (m > nums[i]) {
			m = nums[i];
		}
	}
	return m;
}

int abs(int x) {
	if (x > 0) {
		return x;
	}
	return -x;
}

int pow(int x, int y) {
	int res = 1;
	for (int i = 0; i < y; i++) {
		res *= x;
	}
	return res;
}

// Sort
typedef struct Val {
	int id;
	int num;
} Val;

int cmp(const void* a, const void* b) {
	Val* va = (Val*)a;
	Val* vb = (Val*)b;
	return va->num - vb->num;
}

int main() {
	Scanner* sc = NewScanner();
	FILE* wtr = stdout;
	
	// Read input values
	int A, B, C, K;
	fscanf(sc->fp, "%d %d %d %d", &A, &B, &C, &K);
	
	// Determine the maximum value among A, B, and C
	int ma = max(&A, &B, &C, 3);
	
	// Calculate the sum of the other two values
	int rest = 0;
	if (ma == A) {
		rest += B + C;
	} else if (ma == B) {
		rest += A + C;
	} else {
		rest += A + B;
	}
	
	// Double the maximum value K times
	for (int i = 1; i <= K; i++) {
		ma *= 2;
	}
	
	// Print the final result
	fprintf(wtr, "%d\n", ma + rest);
	
	// 