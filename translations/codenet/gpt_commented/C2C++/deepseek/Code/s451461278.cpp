#include <iostream>
#include <vector>
#include <climits>
#define MAX 100000

// Function prototypes for partitioning and sorting
int Partition(std::vector<char>&, std::vector<int>&, int, int);
void Quicksort(std::vector<char>&, std::vector<int>&, int, int);
void Merge(std::vector<char>&, std::vector<int>&, int, int, int);
void Merge_Sort(std::vector<char>&, std::vector<int>&, int, int);

// Global variable for partition index
int q;

int main(void) {
    // Declare vectors for storing values and characters
    std::vector<int> A(MAX + 1); // Vector for integer values
    std::vector<char> C(MAX + 1); // Vector for characters
    std::vector<char> MC(MAX + 1); // Vector for characters for merge sort
    std::vector<int> MN(MAX + 1); // Vector for integer values for merge sort

    int i, p, n;
    int count = 0; // Counter for stable sorting check

    // Read the number of elements
    std::cin >> n;

    // Read character and integer pairs into vectors
    for (i = 1; i <= n; i++)
        std::cin >> C[i] >> A[i];

    // Copy original vectors to auxiliary vectors for merge sort
    for (i = 1; i <= n; i++) {
        MC[i] = C[i];
        MN[i] = A[i];
    }

    // Perform merge sort on the auxiliary vectors
    Merge_Sort(MC, MN, 1, n);

    // Perform quicksort on the original vectors
    p = 1;
    Quicksort(C, A, p, n);

    // Check if the sorting is stable by comparing original and sorted vectors
    for (i = 1; i <= n; i++) {
        if (MN[i] == A[i] && MC[i] == C[i])
            count++;
    }

    // Output stability result
    if (count == n)
        std::cout << "Stable" << std::endl;
    else
        std::cout << "Not stable" << std::endl;

    // Print the sorted character and integer pairs
    for (i = 1; i <= n; i++)
        std::cout << C[i] << " " << A[i] << std::endl;

    return 0;
}

// Function to partition the vector for quicksort
int Partition(std::vector<char>& C, std::vector<int>& A, int p, int r) {
    int i, j;
    char tmpC;
    int tmpN;

    // Choose the last element as pivot
    char x = C[r];
    int y = A[r];
    i = p - 1;

    // Rearrange elements based on the pivot
    for (j = p; j < r; j++) {
        if (A[j] <= y) {
            i = i + 1;
            // Swap elements to partition the vector
            tmpN = A[j];
            tmpC = C[j];
            A[j] = A[i];
            C[j] = C[i];
            A[i] = tmpN;
            C[i] = tmpC;
        }
    }

    // Place the pivot in the correct position
    tmpN = A[i + 1];
    tmpC = C[i + 1];
    A[i + 1] = A[r];
    C[i + 1] = C[r];
    A[r] = tmpN;
    C[r] = tmpC;

    return i + 1; // Return the pivot index
}

// Function to perform quicksort
void Quicksort(std::vector<char>& C, std::vector<int>& A, int p, int r) {
    // Base case for recursion
    if (p < r) {
        q = Partition(C, A, p, r); // Partition the vector
        Quicksort(C, A, p, q - 1); // Recursively sort the left subarray
        Quicksort(C, A, q + 1, r); // Recursively sort the right subarray
    }
}

// Function to merge two sorted subarrays
void Merge(std::vector<char>& MC, std::vector<int>& MN, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid; // Size of right subarray
    std::vector<int> LN(n1 + 1); // Left subarray for integers
    std::vector<int> RN(n2 + 1); // Right subarray for integers
    std::vector<char> LC(n1 + 1); // Left subarray for characters
    std::vector<char> RC(n2 + 1); // Right subarray for characters
    
    int i, j, k;

    // Copy data to temporary arrays
    for (i = 1; i <= n1; i++) {
        LN[i] = MN[left + i - 1];
        LC[i] = MC[left + i - 1];
    }
    
    for (i = 1; i <= n2; i++) {
        RN[i] = MN[mid + i];
        RC[i] = MC[mid + i];
    }
    
    // Sentinel values for merging
    LN[n1 + 1] = INT_MAX;
    RN[n2 + 1] = INT_MAX;
    
    i = 1; // Index for left subarray
    j = 1; // Index for right subarray
    
    // Merge the temporary arrays back into the original arrays
    for (k = left; k <= right; k++) {
        if (LN[i] <= RN[j]) {
            MN[k] = LN[i];
            MC[k] = LC[i++];
        } else {
            MN[k] = RN[j];
            MC[k] = RC[j++];
        }
    }
}

// Function to perform merge sort
void Merge_Sort(std::vector<char>& MC, std::vector<int>& MN, int left, int right) {
    int mid;

    // Base case for recursion
    if (left < right) {
        mid = (left + right) / 2; // Find the midpoint
        Merge_Sort(MC, MN, left, mid); // Recursively sort the left half
        Merge_Sort(MC, MN, mid + 1, right); // Recursively sort the right half
        Merge(MC, MN, left, mid, right); // Merge the sorted halves
    }
}

