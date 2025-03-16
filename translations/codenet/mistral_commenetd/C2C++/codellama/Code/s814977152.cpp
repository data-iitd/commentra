
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

// Function to compare two integers for qsort
int miyukiti(const void* asumisu, const void* mizuhasu) {
	int isihasu = *(const int*)asumisu, matukisu = *(const int*)mizuhasu;
	// Return -1 if isihasu is less than matukisu, 0 if equal, and 1 if greater
	return isihasu < matukisu ? -1 : isihasu > matukisu;
}

int N; // Number of elements in the array A
int A[114514]; // Input array

int yukinnko; // Number of unique elements in the array tomatu
int tomatu[114514]; // Sorted array of unique elements from A

int mikakosi[114514]; // Array to keep track of whether an element is present or not in the sorted array tomatu

// Function to find the index of an element in the sorted array tomatu
int sumipe(int hayaminn) {
	int satorina = 0, zaasan = yukinnko - 1;
	// Binary search to find the index of hayaminn in the sorted array tomatu
	while (satorina <= zaasan) {
		int yukati = satorina + (zaasan - satorina) / 2;
		if (tomatu[yukati] == hayaminn) return yukati;
		else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
		else zaasan = yukati - 1;
	}
	// Return -1 if the element is not present in the array
	return 114513;
}

int main(void) {
	int inorinn; // Index variable
	int emirinn = 0; // Counter for the number of unique elements

	// Read the number of elements N from the standard input
	if (scanf("%d", &N) != 1) {
		// Return 1 and exit if the number of elements cannot be read
		return 1;
	}

	// Read the elements of the array A from the standard input and store them in tomatu in sorted order
	for (inorinn = 0; inorinn < N; inorinn++) {
		if (scanf("%d", &A[inorinn]) != 1) {
			// Return 1 and exit if an element cannot be read
			return 1;
		}
		tomatu[inorinn] = A[inorinn];
	}

	// Perform quicksort on the array tomatu using the miyukiti function
	qsort(tomatu, N, sizeof(*tomatu), miyukiti);

	// Find the number of unique elements in the array tomatu and store them in yukinnko
	yukinnko = 1;
	for (inorinn = 1; inorinn < N; inorinn++) {
		if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
			tomatu[yukinnko++] = tomatu[inorinn];
		}
	}

	// Initialize the mikakosi array with all elements set to 0
	for (inorinn = 0; inorinn < N; inorinn++) {
		mikakosi[inorinn] = 0;
	}

	// For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
	for (inorinn = 0; inorinn < N; inorinn++) {
		int kugyu = sumipe(A[inorinn]);
		mikakosi[kugyu] = 1;
	}

	// Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
	for (inorinn = 0; inorinn < yukinnko; inorinn++) {
		if (mikakosi[inorinn]) emirinn++;
	}

	// Print the number of unique elements to the standard output
	printf("%d\n", emirinn);

	// Return 0 to indicate successful execution
	return 0;
}

