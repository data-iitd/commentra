#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

// Comparator function for sort to sort the array tomatu
bool miyukiti(int asumisu, int mizuhasu) {
	return asumisu < mizuhasu;
}

// Number of elements
int N;
// Array of elements
std::vector<int> A;

// Number of unique elements
int yukinnko;
// Array to store unique elements
std::vector<int> tomatu;

// Array to store boolean values
std::vector<bool> mikakosi;

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

int main() {
	int inorinn;
	int emirinn = 0;
	// Read the number of elements N from the input
	std::cin >> N;
	// Read the array A from the input and simultaneously copy it to tomatu
	A.resize(N);
	for (inorinn = 0; inorinn < N; inorinn++) {
		std::cin >> A[inorinn];
		tomatu.push_back(A[inorinn]);
	}
	// Sort the array tomatu using the comparator function miyukiti
	std::sort(tomatu.begin(), tomatu.end(), miyukiti);
	// Initialize yukinnko to 1 and store unique elements in tomatu
	yukinnko = 1;
	for (inorinn = 1; inorinn < N; inorinn++) {
		if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
			tomatu[yukinnko++] = tomatu[inorinn];
		}
	}
	// Resize mikakosi to match the number of unique elements
	mikakosi.resize(yukinnko);
	// Iterate over the array A, use sumipe to find the index, and toggle mikakosi
	for (inorinn = 0; inorinn < N; inorinn++) {
		int kugyu = sumipe(A[inorinn]);
		mikakosi[kugyu] = !mikakosi[kugyu];
	}
	// Count and print the number of elements in mikakosi that are set to true
	for (inorinn = 0; inorinn < yukinnko; inorinn++) {
		if (mikakosi[inorinn]) emirinn++;
	}
	std::cout << emirinn << std::endl;
	return 0;
}
