#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a custom data structure 'card' with a character and an integer.
struct card {
    char s;
    int v;
};

// Function 'me' sorts a subarray of 'a' using merge sort algorithm.
void me(vector<card> &a, int l, int m, int r) {
    int n1 = m - l; // Number of elements to be copied to L array.
    int n2 = r - m; // Number of elements to be copied to R array.

    vector<card> L(n1 + 1), R(n2 + 1); // Create temporary arrays L and R.

    // Copy elements from 'a' to L and R arrays.
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i];

    // Set the last elements of L and R arrays with a large value to mark the end of each array.
    L[n1].v = R[n2].v = 2000000000;

    // Merge sorted subarrays L and R back to 'a'.
    int i = 0, j = 0;
    for (int k = l; k < r; k++) {
        // Compare elements from L and R arrays and copy smaller one to 'a'.
        if (L[i].v <= R[j].v) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }
}

// Recursive function 'ms' to merge sort the entire array 'a'.
void ms(vector<card> &a, int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        // Recursively sort left and right subarrays and then merge them.
        ms(a, l, m);
        ms(a, m, r);
        // Merge sorted subarrays.
        me(a, l, m, r);
    }
}

// Function 'partiton' partitions an array into two parts.
int partiton(vector<card> &a, int p, int r) {
    card x = a[r]; // Set 'x' as the last element of the array.
    int i = p - 1; // Index of the last element in the left subarray.

    // Iterate through the array from index p to r-1 and swap elements if they are smaller than 'x'.
    for (int j = p; j < r; j++) {
        if (a[j].v <= x.v) {
            i++; // Increment index of the last element in the left subarray.
            swap(a[i], a[j]); // Swap elements a[i] and a[j].
        }
    }
    swap(a[i + 1], a[r]); // Swap the last elements of the left and right subarrays.
    return i + 1; // Return the index 'i+1' as the pivot index.
}

// Function 'qs' implements quicksort algorithm to sort the array 'a'.
void qs(vector<card> &a, int p, int r) {
    if (p < r) {
        int q = partiton(a, p, r);
        // Recursively sort the left and right subarrays.
        qs(a, p, q - 1);
        qs(a, q + 1, r);
    }
}

// Main function to read input, sort the array using merge sort and quicksort, and print the sorted array.
int main() {
    int n;
    cin >> n;
    vector<card> a(n), b(n);
    string s;
    bool stable = true;

    // Read input cards and initialize 'a' and 'b' arrays.
    for (int i = 0; i < n; i++) {
        cin >> s >> a[i].v;
        a[i].s = b[i].s = s[0]; // Set the character part of 'a' and 'b'.
        b[i].v = a[i].v; // Set the integer part of 'b' equal to the integer value of the input card.
    }

    // Merge sort the 'a' array.
    ms(a, 0, n);

    // Quick sort the 'b' array.
    qs(b, 0, n - 1);

    // Compare 'a' and 'b' arrays to check stability.
    for (int i = 0; i < n; i++) {
        if (a[i].s != b[i].s) {
            stable = false;
        }
    }

    // Print the result and the sorted array 'b'.
    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i].s << " " << b[i].v << endl;
    }

    return 0;
}

// <END-OF-CODE>
