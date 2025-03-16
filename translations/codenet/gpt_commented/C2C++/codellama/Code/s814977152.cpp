#include <iostream>
#include <algorithm>

// Comparison function for sort to sort integers
bool miyukiti(int asumisu, int mizuhasu) {
    return asumisu < mizuhasu;
}

// Global variables
int N; // Number of elements
int A[114514]; // Array to hold input elements

int yukinnko; // Count of unique elements
int tomatu[114514]; // Array to hold sorted elements

int mikakosi[114514]; // Array to track occurrences of elements

// Function to perform binary search on the sorted array
int sumipe(int hayaminn) {
    int satorina = 0, zaasan = yukinnko - 1;
    while (satorina <= zaasan) {
        int yukati = satorina + (zaasan - satorina) / 2;
        if (tomatu[yukati] == hayaminn) return yukati; // Found the element
        else if (tomatu[yukati] < hayaminn) satorina = yukati + 1; // Search in the right half
        else zaasan = yukati - 1; // Search in the left half
    }
    return 114513; // Element not found
}

// Main function
int main() {
    int inorinn; // Loop variable for input
    int emirinn = 0; // Counter for unique elements

    // Read the number of elements
    std::cin >> N;

    // Read the elements into array A and copy to tomatu
    for (inorinn = 0; inorinn < N; inorinn++) {
        std::cin >> A[inorinn];
        tomatu[inorinn] = A[inorinn]; // Copying input to sorted array
    }

    // Sort the array of elements
    std::sort(tomatu, tomatu + N, miyukiti);

    // Remove duplicates from the sorted array
    yukinnko = 1; // Start with the first unique element
    for (inorinn = 1; inorinn < N; inorinn++) {
        if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
            tomatu[yukinnko++] = tomatu[inorinn]; // Add unique element
        }
    }

    // Track occurrences of each element in the original array
    for (inorinn = 0; inorinn < N; inorinn++) {
        int kugyu = sumipe(A[inorinn]); // Find index of element in sorted array
        mikakosi[kugyu] = !mikakosi[kugyu]; // Toggle occurrence
    }

    // Count the number of unique elements
    for (inorinn = 0; inorinn < yukinnko; inorinn++) {
        if (mikakosi[inorinn]) emirinn++; // Increment count for unique occurrences
    }

    // Output the count of unique elements
    std::cout << emirinn << std::endl;
    return 0; // Successful execution
}

