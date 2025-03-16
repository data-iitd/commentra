
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function out is used for printing output to the console
void out(int x) {
	printf("%d\n", x);
}

// Function getInt is used for reading an integer value from the standard input
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function getString is used for reading a string value from the standard input
char* getString() {
	char* s = (char*)malloc(100 * sizeof(char));
	scanf("%s", s);
	return s;
}

// Function max returns the maximum value between two integers
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function min returns the minimum value between two integers
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function asub returns the absolute difference between two integers
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Function abs returns the absolute value of an integer
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Function lowerBound returns the index of the first element in the array that is greater than or equal to the given value
int lowerBound(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] < x) {
		i++;
	}
	return i;
}

// Function upperBound returns the index of the first element in the array that is greater than the given value
int upperBound(int a[], int n, int x) {
	int i = 0;
	while (i < n && a[i] <= x) {
		i++;
	}
	return i;
}

// Structure shop represents a data structure for storing two integers
typedef struct {
	int a;
	int b;
} shop;

// Function compareShops compares two shop data structures and returns true if the first one should come before the second one in a sorted array
int compareShops(shop a, shop b) {
	return a.a < b.a;
}

// Function sortShops sorts an array of shop data structures in ascending order based on the 'a' field of each shop
void sortShops(shop a[], int n) {
	int i, j;
	shop temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0 && compareShops(temp, a[j]); j--) {
			a[j + 1] = a[j];
		}
		a[j + 1] = temp;
	}
}

// Function main is the entry point of the program
int main() {
	// Read the number of shops N and the number of customers M from the standard input
	int N = getInt();
	int M = getInt();
	// Initialize an array of shop data structures named s with a length of N
	shop s[N];
	// For each shop in the array
	for (int i = 0; i < N; i++) {
		// Read the capacity 'a' and demand 'b' of the shop from the standard input
		s[i].a = getInt();
		s[i].b = getInt();
	}
	// Sort the array in ascending order based on the 'a' field of each shop
	sortShops(s, N);

	// Initialize a variable named total to store the total capacity used by the shops
	int total = 0;
	// For each shop in the sorted array
	for (int i = 0; i < N; i++) {
		// Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
		int n = min(s[i].b, M);
		// Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
		total += n * s[i].a;
		// Decrease the maximum demand by the number of customers served by the shop
		M -= n;
		// If the maximum demand becomes zero, break the loop
		if (M == 0) {
			break;
		}
	}
	// Print the total capacity used by the shops
	out(total);
	return 0;
}

