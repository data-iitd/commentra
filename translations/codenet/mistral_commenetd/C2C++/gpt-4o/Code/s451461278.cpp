#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

// Function declarations
int Partition(std::vector<char>& C, std::vector<int>& A, int p, int r);
void Quicksort(std::vector<char>& C, std::vector<int>& A, int p, int r);
void Merge(std::vector<char>& MC, std::vector<int>& MN, int left, int mid, int right);
void Merge_Sort(std::vector<char>& MC, std::vector<int>& MN, int left, int right);

// Main function
int main() {
    std::vector<int> A(MAX + 1); // Dynamically allocated array for integers A
    std::vector<char> C(MAX + 1); // Dynamically allocated array for characters C
    std::vector<char> MC(MAX + 1); // Dynamically allocated array for characters MC (Modified C)
    std::vector<int> MN(MAX + 1); // Dynamically allocated array for integers MN (Modified N)

    int n; // Number of elements
    int count = 0;

    std::cin >> n; // Read the number of elements n

    // Read characters and integers from the standard input
    for (int i = 1; i <= n; i++)
        std::cin >> C[i] >> A[i];

    // Copy characters and integers from A to MC and MN respectively
    for (int i = 1; i <= n; i++) {
        MC[i] = C[i];
        MN[i] = A[i];
    }

    // Merge sort on MC and MN arrays
    Merge_Sort(MC, MN, 1, n);

    // Quick sort on C and A arrays
    int p = 1;
    Quicksort(C, A, p, n);

    // Check if the arrays are equal after sorting
    for (int i = 1; i <= n; i++) {
        if (MN[i] == A[i] && MC[i] == C[i])
            count++;
    }

    // Print the result
    if (count == n)
        std::cout << "Stable\n";
    else
        std::cout << "Not stable\n";

    // Print the sorted arrays
    for (int i = 1; i <= n; i++)
        std::cout << C[i] << " " << A[i] << "\n";

    return 0;
}

// Partition function for quick sort
int Partition(std::vector<char>& C, std::vector<int>& A, int p, int r) {
    int i, j; // Variables declaration
    char tmpC, x; // Variables declaration
    int tmpN, y; // Variables declaration

    // Set the pivot element as the last element of the array
    x = C[r];
    y = A[r];

    // Set the initial index of the left partition as p - 1
    i = p - 1;

    // Iterate through the array from p to r - 1
    for (j = p; j < r; j++) {
        // If the current element is smaller than the pivot, increment i and swap the elements
        if (A[j] <= y) {
            i = i + 1;
            std::swap(A[j], A[i]);
            std::swap(C[j], C[i]);
        }
    }

    // Swap the pivot element with the element at index i + 1
    std::swap(A[i + 1], A[r]);
    std::swap(C[i + 1], C[r]);

    // Return the index of the pivot element
    return i + 1;
}

// Quicksort function
void Quicksort(std::vector<char>& C, std::vector<int>& A, int p, int r) {
    // Base case: if p is less than r, recursively call Partition and Quicksort functions
    if (p < r) {
        int q = Partition(C, A, p, r);
        Quicksort(C, A, p, q - 1);
        Quicksort(C, A, q + 1, r);
    }
}

// Merge function for merge sort
void Merge(std::vector<char>& MC, std::vector<int>& MN, int left, int mid, int right) {
    int n1 = mid - left + 1; // Calculate the size of the left partition
    int n2 = right - mid; // Calculate the size of the right partition
    std::vector<int> LN(n1 + 1); // Left partition of integers
    std::vector<int> RN(n2 + 1); // Right partition of integers
    std::vector<char> LC(n1 + 1); // Left partition of characters
    std::vector<char> RC(n2 + 1); // Right partition of characters

    // Copy the left partition to LN and LC arrays
    for (int i = 1; i <= n1; i++) {
        LN[i] = MN[left + i - 1];
        LC[i] = MC[left + i - 1];
    }

    // Copy the right partition to RN and RC arrays
    for (int i = 1; i <= n2; i++) {
        RN[i] = MN[mid + i];
        RC[i] = MC[mid + i];
    }

    // Set the sentinel values for LN and RN arrays
    LN[n1 + 1] = 1000000000;
    RN[n2 + 1] = 1000000000;

    // Merge the left and right partitions into the original arrays
    int i = 1, j = 1, k = left;
    while (i <= n1 && j <= n2) {
        if (LN[i] <= RN[j]) {
            MN[k] = LN[i];
            MC[k] = LC[i];
            i++;
        } else {
            MN[k] = RN[j];
            MC[k] = RC[j];
            j++;
        }
        k++;
    }
}

// Merge sort function
void Merge_Sort(std::vector<char>& MC, std::vector<int>& MN, int left, int right) {
    int mid; // Variable declaration

    // Base case: if left is less than right, recursively call Merge_Sort and Merge functions
    if (left < right) {
        mid = (left + right) / 2;
        Merge_Sort(MC, MN, left, mid);
        Merge_Sort(MC, MN, mid + 1, right);
        Merge(MC, MN, left, mid, right);
    }
}

// <END-OF-CODE>
