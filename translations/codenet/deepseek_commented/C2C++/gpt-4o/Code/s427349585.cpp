#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the card structure
struct Card {
    char s;
    int v;
};

// Define arrays for left and right subarrays
vector<Card> L(100000 / 2 + 2), R(100000 / 2 + 2);

// Merge function to merge two subarrays
void merge(vector<Card>& a, int l, int m, int r) {
    int n1 = m - l;
    int n2 = r - m;

    // Copy elements to left and right subarrays
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + i];

    // Sentinel values to avoid checking for array boundaries
    L[n1].v = R[n2].v = 2000000000;

    int i = 0, j = 0;

    // Merge the two subarrays back into the original array
    for (int k = l; k < r; k++) {
        if (L[i].v <= R[j].v) {
            a[k] = L[i++];
        } else {
            a[k] = R[j++];
        }
    }
}

// Merge sort function to sort the array
void mergeSort(vector<Card>& a, int l, int r) {
    if (l + 1 < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m, r);
        merge(a, l, m, r);
    }
}

// Partition function to partition the array around a pivot
int partition(vector<Card>& a, int p, int r) {
    Card x = a[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (a[j].v <= x.v) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

// Quick sort function to sort the array
void quickSort(vector<Card>& a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quickSort(a, p, q - 1);
        quickSort(a, q + 1, r);
    }
}

// Main function to read input, sort the arrays, check for stability, and print the result
int main() {
    int n;
    cin >> n;
    vector<Card> a(n), b(n);

    // Read each card's suit and value
    for (int i = 0; i < n; i++) {
        string s;
        int v;
        cin >> s >> v;
        a[i].s = b[i].s = s[0];
        a[i].v = b[i].v = v;
    }

    // Sort the array using merge sort
    mergeSort(a, 0, n);

    // Sort the array using quick sort
    quickSort(b, 0, n - 1);

    // Check if the sorting is stable
    bool stable = true;
    for (int i = 0; i < n; i++) {
        if (a[i].s != b[i].s) {
            stable = false;
            break;
        }
    }

    // Print the stability status
    if (stable) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << b[i].s << " " << b[i].v << endl;
    }

    return 0;
}

// <END-OF-CODE>
