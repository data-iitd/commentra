#include <iostream>
#include <vector>
#include <algorithm>

// Comparator function for sort to sort the array tomatu
bool miyukiti(int isihasu, int matukisu) {
    return isihasu < matukisu;
}

// Number of elements
int N;
// Array of elements
std::vector<int> A(114514);

// Number of unique elements
int yukinnko;
// Array to store unique elements
std::vector<int> tomatu(114514);

// Array to store boolean values
std::vector<bool> mikakosi(114514, false);

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
    if (!(std::cin >> N)) return 1;
    // Read the array A from the input and simultaneously copy it to tomatu
    for (inorinn = 0; inorinn < N; inorinn++) {
        if (!(std::cin >> A[inorinn])) return 1;
        tomatu[inorinn] = A[inorinn];
    }
    // Sort the array tomatu using the comparator function miyukiti
    std::sort(tomatu.begin(), tomatu.begin() + N, miyukiti);
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
    std::cout << emirinn << std::endl;
    return 0;
}

// <END-OF-CODE>
