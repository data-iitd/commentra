#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

// Function prototypes for partitioning and sorting
int Partition(char [], int [], int, int);
void Quicksort(char [], int [], int, int);
void Merge(char [], int [], int, int, int);
void Merge_Sort(char [], int [], int, int);

// Global variable for partition index
int q;

int main(void) {
    // Declare arrays for storing values and characters
    int A[MAX + 1]; // Array for integer values
    char C[MAX + 1]; // Array for characters
    char MC[MAX + 1]; // Array for characters for merge sort
    int MN[MAX + 1]; // Array for integer values for merge sort

    int i, p, n;
    int count = 0; // Counter for stable sorting check

    // Read the number of elements
    scanf("%d", &n);

    // Read character and integer pairs into arrays
    for (i = 1; i <= n; i++)
        scanf(" %c %d", &C[i], &A[i]);

    // Copy original arrays to auxiliary arrays for merge sort
    for (i = 1; i <= n; i++) {
        MC[i] = C[i];
        MN[i] = A[i];
    }

    // Perform merge sort on the auxiliary arrays
    Merge_Sort(MC, MN, 1, n);

    // Perform quicksort on the original arrays
    p = 1;
    Quicksort(C, A, p, n);

    // Check if the sorting is stable by comparing original and sorted arrays
    for (i = 1; i <= n; i++) {
        if (MN[i] == A[i] && MC[i] == C[i])
            count++;
    }

    // Output stability result
    if (count == n)
        printf("Stable\n");
    else
        printf("Not stable\n");

    // Print the sorted character and integer pairs
    for (i = 1; i <= n; i++)
        printf("%c %d\n", C[i], A[i]);

    return 0;
}

// Function to partition the array for quicksort
int Partition(char C[], int A[], int p, int r) {
    int i, j;
    char tmpC, x;
    int tmpN, y;

    // Choose the last element as pivot
    x = C[r];
    y = A[r];
    i = p - 1;

    // Rearrange elements based on the pivot
    for (j = p; j < r; j++) {
        if (A[j] <= y) {
            i = i + 1;
            // Swap elements to partition the array
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
void Quicksort(char C[], int A[], int p, int r) {
    // Base case for recursion
    if (p < r) {
        q = Partition(C, A, p, r); // Partition the array
        Quicksort(C, A, p, q - 1); // Recursively sort the left subarray
        Quicksort(C, A, q + 1, r); // Recursively sort the right subarray
    }
}

// Function to merge two sorted subarrays
void Merge(char MC[], int MN[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid; // Size of right subarray
    int LN[n1 + 1]; // Left subarray for integers
    int RN[n2 + 1]; // Right subarray for integers
    int LC[n1 + 1]; // Left subarray for characters
    int RC[n2 + 1]; // Right subarray for characters
    
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
    LN[n1 + 1] = 1000000000;
    RN[n2 + 1] = 1000000000;
    
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
void Merge_Sort(char MC[], int MN[], int left, int right) {
    int mid;

    // Base case for recursion
    if (left < right) {
        mid = (left + right) / 2; // Find the midpoint
        Merge_Sort(MC, MN, left, mid); // Recursively sort the left half
        Merge_Sort(MC, MN, mid + 1, right); // Recursively sort the right half
        Merge(MC, MN, left, mid, right); // Merge the sorted halves
    }
}

