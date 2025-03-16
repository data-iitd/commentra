#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a card with a character and an integer value
struct Card {
    char s; // Character representing the card's suit or type
    int v;  // Integer representing the card's value
};

// Merge function to combine two sorted halves of the array
void merge(vector<Card>& a, int l, int m, int r) {
    int n1 = m - l; // Size of the left half
    int n2 = r - m; // Size of the right half

    vector<Card> L(n1 + 1), R(n2 + 1); // Temporary arrays

    // Copy data to temporary arrays L and R
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i];

    // Sentinel values to avoid out-of-bounds access
    L[n1].v = R[n2].v = 2000000000;

    // Merge the temporary arrays back into the original array
    int i = 0; // Index for left array
    int j = 0; // Index for right array
    for (int k = l; k < r; k++) {
        if (L[i].v <= R[j].v) {
            a[k] = L[i++]; // Take from left if it's smaller or equal
        } else {
            a[k] = R[j++]; // Take from right otherwise
        }
    }
}

// Merge sort function to recursively sort the array
void mergeSort(vector<Card>& a, int l, int r) {
    if (l + 1 < r) { // Base case: if the segment has more than one element
        int m = (l + r) / 2; // Find the midpoint
        mergeSort(a, l, m); // Sort the left half
        mergeSort(a, m, r); // Sort the right half
        merge(a, l, m, r); // Merge the sorted halves
    }
}

// Partition function for quicksort
int partition(vector<Card>& a, int p, int r) {
    Card x = a[r]; // Choose the last element as the pivot
    int i = p - 1; // Index of smaller element
    for (int j = p; j < r; j++) {
        if (a[j].v <= x.v) { // If current element is smaller than or equal to pivot
            i++; // Increment index of smaller element
            swap(a[i], a[j]); // Swap elements
        }
    }
    swap(a[i + 1], a[r]); // Swap the pivot element with the element at i + 1
    return i + 1; // Return the partitioning index
}

// Quicksort function to recursively sort the array
void quickSort(vector<Card>& a, int p, int r) {
    if (p < r) { // Base case: if the segment has more than one element
        int q = partition(a, p, r); // Partition the array
        quickSort(a, p, q - 1); // Recursively sort the left half
        quickSort(a, q + 1, r); // Recursively sort the right half
    }
}

// Main function
int main() {
    int n;
    cin >> n; // Read the number of cards

    vector<Card> a(n), b(n); // Arrays to hold the cards for sorting
    string s; // Temporary storage for the character input
    bool stable = true; // Flag to check if the sorting is stable

    // Read the cards into both arrays a and b
    for (int i = 0; i < n; i++) {
        cin >> s >> a[i].v; // Read character and value
        a[i].s = b[i].s = s[0]; // Store the character
        b[i].v = a[i].v; // Store the value
    }

    // Perform merge sort on array a
    mergeSort(a, 0, n);
    // Perform quicksort on array b
    quickSort(b, 0, n - 1);

    // Check if the sorting is stable by comparing the original and sorted arrays
    for (int i = 0; i < n; i++) {
        if (a[i].s != b[i].s) {
            stable = false; // If any character differs, it's not stable
        }
    }

    // Output the stability result
    cout << (stable ? "Stable" : "Not stable") << endl;

    // Print the sorted array
    for (const auto& card : b) {
        cout << card.s << " " << card.v << endl;
    }

    return 0; // Return success
}

// <END-OF-CODE>
