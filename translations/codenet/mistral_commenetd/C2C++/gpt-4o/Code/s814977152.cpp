#include <iostream>
#include <vector>
#include <algorithm>

// Function to compare two integers for std::sort
int miyukiti(const int& asumisu, const int& mizuhasu) {
    // Return -1 if asumisu is less than mizuhasu, 0 if equal, and 1 if greater
    return (asumisu < mizuhasu) ? -1 : (asumisu > mizuhasu);
}

int main() {
    int N; // Number of elements in the array A
    std::cin >> N; // Read the number of elements N

    std::vector<int> A(N); // Input array
    std::vector<int> tomatu(N); // Sorted array of unique elements from A

    // Read the elements of the array A from the standard input
    for (int inorinn = 0; inorinn < N; inorinn++) {
        std::cin >> A[inorinn];
        tomatu[inorinn] = A[inorinn];
    }

    // Perform quicksort on the array tomatu using std::sort
    std::sort(tomatu.begin(), tomatu.end());

    // Find the number of unique elements in the array tomatu
    int yukinnko = 1;
    for (int inorinn = 1; inorinn < N; inorinn++) {
        if (tomatu[inorinn] != tomatu[yukinnko - 1]) {
            tomatu[yukinnko++] = tomatu[inorinn];
        }
    }

    // Initialize the mikakosi array with all elements set to 0
    std::vector<int> mikakosi(yukinnko, 0);

    // For each element in the array A, find its index in the sorted array tomatu and mark it as present in the mikakosi array
    for (int inorinn = 0; inorinn < N; inorinn++) {
        auto it = std::lower_bound(tomatu.begin(), tomatu.begin() + yukinnko, A[inorinn]);
        if (it != tomatu.begin() + yukinnko && *it == A[inorinn]) {
            int kugyu = it - tomatu.begin();
            mikakosi[kugyu] = 1;
        }
    }

    // Count the number of unique elements in the array tomatu by counting the number of elements with mikakosi[i] set to 1
    int emirinn = 0;
    for (int inorinn = 0; inorinn < yukinnko; inorinn++) {
        if (mikakosi[inorinn]) emirinn++;
    }

    // Print the number of unique elements to the standard output
    std::cout << emirinn << std::endl;

    return 0; // Indicate successful execution
}

// <END-OF-CODE>
