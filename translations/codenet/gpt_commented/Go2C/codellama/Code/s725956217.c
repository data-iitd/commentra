#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// out is a utility function to print output to the console.
void out(int x) {
	printf("%d\n", x);
}

// getInt reads an integer from input and returns it.
int getInt() {
	int i;
	scanf("%d", &i);
	return i;
}

// getString reads a string from input and returns it.
char *getString() {
	char *s = malloc(100 * sizeof(char));
	scanf("%s", s);
	return s;
}

// max returns the maximum of two integers.
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

// min returns the minimum of two integers.
int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

// asub returns the absolute difference between two integers.
int asub(int a, int b) {
	if (a > b) {
		return a - b;
	}
	return b - a;
}

// abs returns the absolute value of an integer.
int abs(int a) {
	if (a >= 0) {
		return a;
	}
	return -a;
}

// lowerBound returns the index of the first element in a that is not less than x.
int lowerBound(int *a, int n, int x) {
	int i = 0;
	while (i < n && a[i] < x) {
		i++;
	}
	return i;
}

// upperBound returns the index of the first element in a that is greater than x.
int upperBound(int *a, int n, int x) {
	int i = 0;
	while (i < n && a[i] <= x) {
		i++;
	}
	return i;
}

// shop represents a shop with a price (a) and available quantity (b).
typedef struct {
	int a;
	int b;
} shop;

// Datas is a slice of shop, implementing sort.Interface.
typedef struct {
	int len;
	shop *data;
} Datas;

// Len returns the number of elements in the slice.
int Datas_Len(Datas *p) {
	return p->len;
}

// Swap exchanges the elements with indexes i and j.
void Datas_Swap(Datas *p, int i, int j) {
	shop tmp = p->data[i];
	p->data[i] = p->data[j];
	p->data[j] = tmp;
}

// Less reports whether the element with index i should sort before the element with index j.
bool Datas_Less(Datas *p, int i, int j) {
	return p->data[i].a < p->data[j].a; // Sort by price (a)
}

// main is the entry point of the program.
int main() {
	// Read the number of shops (N) and the total quantity needed (M)
	int N = getInt();
	int M = getInt();
	Datas s = {N, malloc(N * sizeof(shop))}; // Create a slice to hold the shops

	// Read the price and quantity for each shop
	for (int i = 0; i < N; i++) {
		int a = getInt(); // Read price (a)
		int b = getInt(); // Read quantity (b)
		s.data[i] = (shop){a, b}; // Store the shop information
	}
	Datas_Sort(&s); // Sort the shops by price

	int total = 0; // Initialize total cost
	// Calculate the total cost based on available quantities and prices
	for (int i = 0; i < s.len; i++) {
		int n = min(s.data[i].b, M); // Determine how much can be bought from this shop
		total += n * s.data[i].a; // Add to total cost
		M -= n; // Decrease the remaining quantity needed
		if (M == 0) {
			break; // Stop if the required quantity is met
		}
	}
	out(total); // Output the total cost
	return 0;
}

