
#include <iostream>
#include <algorithm>

using namespace std;

// Comparison function for sort to sort integers
bool miyukiti(int a, int b) {
    return a < b;
}

int main() {
    int N; // Number of elements
    cin >> N; // Read the number of elements

    int A[N]; // Array to hold input elements
    for (int i = 0; i < N; i++) {
        cin >> A[i]; // Read the elements into array A
    }

    int yukinnko = N; // Count of unique elements
    int tomatu[N]; // Array to hold sorted elements
    copy(A, A + N, tomatu); // Copy input to sorted array

    sort(tomatu, tomatu + N, miyukiti); // Sort the array of elements

    int mikakosi[N]; // Array to track occurrences of elements
    fill(mikakosi, mikakosi + N, 0); // Initialize all elements to 0

    for (int i = 0; i < N; i++) {
        int kugyu = lower_bound(tomatu, tomatu + yukinnko, A[i]) - tomatu; // Find index of element in sorted array
        mikakosi[kugyu] =!mikakosi[kugyu]; // Toggle occurrence
    }

    int emirinn = 0; // Counter for unique elements
    for (int i = 0; i < yukinnko; i++) {
        if (mikakosi[i]) emirinn++; // Increment count for unique occurrences
    }

    cout << emirinn << endl; // Output the count of unique elements

    return 0; // Successful execution
}

