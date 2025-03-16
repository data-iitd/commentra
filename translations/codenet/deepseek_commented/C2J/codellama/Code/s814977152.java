#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort to sort the array tomatu
int miyukiti(const void* asumisu, const void* mizuhasu) {
	int isihasu = *(const int*)asumisu, matukisu = *(const int*)mizuhasu;
	return isihasu < matukisu ? -1 : isihasu > matukisu;
}

// Number of elements
int N;
// Array of elements
int A[114514];

// Number of unique elements
int yukinnko;
// Array to store unique elements
int tomatu[114514];

// Array to store boolean values
int mikakosi[114514];

// Function to perform binary search to find the index of an element in the sorted array tomatu
int sumipe(int hayaminn) {
	int satorina = 0, zaasan = yukinnko - 1;
	while (satorina <= zaasan) {
		int yukati = satorina + (zaasan - satorina) / 2;
		if (tomatu[yukati] == hayaminn) return yukati;
		else if (tomatu[yukati] < hayaminn) satorina = yukati + 1;
		else zaasan = yukati - 1;
	}
	return 114513;
}

int main(void) {
	int inorinn;
	int emirinn = 0;
	// Read the number of elements N from the input
	if (scanf("%d", &N) != 1) return 1;
	// Read the array A from the input and simultaneously copy it to tomatu
	for (inorinn = 0; inorinn < N; inorinn++) {
		if (scanf("%d", &A[inorinn]) != 1) return 1;
		tomatu[inorinn] = A[inorinn];
	}
	// Sort the array tomatu using the comparator function miyukiti
	qsort(tomatu, N, sizeof(*tomatu), miyukiti);
	// Initialize yukinnko to 1 and store unique elements in tomatu
	yukinnko = 1;
	for (inorinn = 1; inorinn < N; inorinn++) {
		if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
			tomatu[yukinnko++] = tomatu[inorinn];
		}
	}
	// Iterate over the array A, use sumipe to find the index, and toggle mikakosi
	for (inorinn = 0; inorinn < N; inorinn++) {
		int kugyu = sumipe(A[inorinn]);
		mikakosi[kugyu] = !mikakosi[kugyu];
	}
	// Count and print the number of elements in mikakosi that are set to true
	for (inorinn = 0; inorinn < yukinnko; inorinn++) {
		if (mikakosi[inorinn]) emirinn++;
	}
	printf("%d\n", emirinn);
	return 0;
}

