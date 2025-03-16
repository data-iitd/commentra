#include <iostream>
#include <vector>
#include <algorithm>

// Comparison function for sort to sort integers
bool miyukiti(int a, int b) {
    return a < b;
}

// Global variables
int N; // Number of elements
std::vector<int> A; // Vector to hold input elements

int yukinnko; // Count of unique elements
std::vector<int> tomatu; // Vector to hold sorted elements

std::vector<int> mikakosi; // Vector to track occurrences of elements

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
    int emirinn = 0; // Counter for unique elements

    // Read the number of elements
    std::cin >> N;
    A.resize(N);
    tomatu.resize(N);
    mikakosi.resize(N, 0); // Initialize occurrences vector

    // Read the elements into vector A and copy to tomatu
    for (int inorinn = 0; inorinn < N; inorinn++) {
        std::cin >> A[inorinn];
        tomatu[inorinn] = A[inorinn]; // Copying input to sorted array
    }

    // Sort the array of elements
    std::sort(tomatu.begin(), tomatu.end(), miyukiti);

    // Remove duplicates from the sorted array
    yukinnko = 1; // Start with the first unique element
    for (int inorinn = 1; inorinn < N; inorinn++) {
        if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
            tomatu[yukinnko++] = tomatu[inorinn]; // Add unique element
        }
    }

    // Track occurrences of each element in the original array
    for (int inorinn = 0; inorinn < N; inorinn++) {
        int kugyu = sumipe(A[inorinn]); // Find index of element in sorted array
        mikakosi[kugyu] = !mikakosi[kugyu]; // Toggle occurrence
    }

    // Count the number of unique elements
    for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
        if (mikakosi[inorinn]) emirinn++; // Increment count for unique occurrences
    }

    // Output the count of unique elements
    std::cout << emirinn << std::endl;
    return 0; // Successful execution
}

// <END-OF-CODE>
