
#include <iostream>
#include <algorithm>

using namespace std;

// Comparator function for sort to sort the array tomatu
bool miyukiti(int hayaminn, int mizuhasu) {
	return hayaminn < mizuhasu;
}

int main(void) {
	int inorinn;
	int emirinn = 0;
	// Read the number of elements N from the input
	cin >> N;
	// Read the array A from the input and simultaneously copy it to tomatu
	for (inorinn = 0; inorinn < N; inorinn++) {
		cin >> A[inorinn];
		tomatu[inorinn] = A[inorinn];
	}
	// Sort the array tomatu using the comparator function miyukiti
	sort(tomatu, tomatu + N, miyukiti);
	// Initialize yukinnko to 1 and store unique elements in tomatu
	yukinnko = 1;
	for (inorinn = 1; inorinn < N; inorinn++) {
		if (tomatu[inorinn]!= tomatu[yukinnko - 1]) {
			tomatu[yukinnko++] = tomatu[inorinn];
		}
	}
	// Iterate over the array A, use sumipe to find the index, and toggle mikakosi
	for (inorinn = 0; inorinn < N; inorinn++) {
		int kugyu = sumipe(A[inorinn]);
		mikakosi[kugyu] =!mikakosi[kugyu];
	}
	// Count and print the number of elements in mikakosi that are set to true
	for (inorinn = 0; inorinn < yukinnko; inorinn++) {
		if (mikakosi[inorinn]) emirinn++;
	}
	cout << emirinn << endl;
	return 0;
}

