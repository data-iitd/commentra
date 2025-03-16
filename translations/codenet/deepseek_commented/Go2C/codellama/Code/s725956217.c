#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to print output.
void out(int x) {
	printf("%d\n", x);
}

// Function to read an integer from input.
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// Function to read a string from input.
char* getString() {
	char* s = (char*)malloc(100 * sizeof(char));
	scanf("%s", s);
	return s;
}

// Function to return the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// Function to return the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// Function to return the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// Function to return the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// Function to find the lower bound index of a value in a sorted array.
int lowerBound(int a[], int x, int n) {
	int i = 0;
	while (i < n) {
		if (a[i] >= x) {
			return i;
		}
		i++;
	}
	return i;
}

// Function to find the upper bound index of a value in a sorted array.
int upperBound(int a[], int x, int n) {
	int i = 0;
	while (i < n) {
		if (a[i] > x) {
			return i;
		}
		i++;
	}
	return i;
}

// Struct to represent a shop with its price and stock.
typedef struct {
	int a;
	int b;
} shop;

// Slice of shops to implement sorting.
typedef struct {
	shop* data;
	int size;
	int capacity;
} Datas;

// Implementing sort.Interface for Datas.
int datas_len(Datas* p) {
	return p->size;
}

void datas_swap(Datas* p, int i, int j) {
	shop temp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = temp;
}

int datas_less(Datas* p, int i, int j) {
	return p->data[i].a < p->data[j].a;
}

// Main function to execute the program logic.
int main() {
	// Read the number of shops and the amount of items to buy.
	int N, M = getInt(), total = 0;

	// Create a slice of shops and read each shop's price and stock.
	Datas s = {(shop*)malloc(N * sizeof(shop)), 0, N};
	for (int i = 0; i < N; i++) {
		int a, b = getInt();
		s.data[i] = (shop){a, b};
	}

	// Sort the shops by price.
	for (int i = 0; i < s.size; i++) {
		for (int j = i + 1; j < s.size; j++) {
			if (datas_less(&s, i, j)) {
				datas_swap(&s, i, j);
			}
		}
	}

	// Calculate the total cost of buying the required number of items.
	for (int i = 0; i < s.size; i++) {
		// Determine the number of items to buy from the current shop.
		int n = min(s.data[i].b, M);
		// Update the total cost and the remaining items to buy.
		total += n * s.data[i].a;
		M -= n;
		// Break if all items are bought.
		if (M == 0) {
			break;
		}
	}

	// Print the total cost.
	out(total);

	// Free the allocated memory.
	free(s.data);

	return 0;
}

