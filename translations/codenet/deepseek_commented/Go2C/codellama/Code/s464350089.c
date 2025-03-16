
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mod 1000000007

// 1MB
#define ioBufferSize 1 * 1024 * 1024

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
	printf("No\n");
} else {
	printf("Yes\n");
}

// Read the next integer
int nextInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Read the next string
char* next() {
	char* s = (char*)malloc(sizeof(char) * 1000000);
	scanf("%s", s);
	return s;
}

// Read the next line
char* nextLine() {
	char* s = (char*)malloc(sizeof(char) * 1000000);
	fgets(s, 1000000, stdin);
	return s;
}

// Read the next integer array
int* nextIntArray(int n) {
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextInt();
	}
	return arr;
}

// Read the next string array
char** nextStringArray(int n) {
	char** arr = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = next();
	}
	return arr;
}

// Read the next line array
char** nextLineArray(int n) {
	char** arr = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLine();
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextStringArray(m);
	}
	return arr;
}

// Read the next line matrix
char*** nextLineMatrix(int n, int m) {
	char*** arr = (char***)malloc(sizeof(char**) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextLineArray(m);
	}
	return arr;
}

// Read the next integer matrix
int** nextIntMatrix(int n, int m) {
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = nextIntArray(m);
	}
	return arr;
}

// Read the next string matrix
char*** nextStringMatrix(int n, int m) {
