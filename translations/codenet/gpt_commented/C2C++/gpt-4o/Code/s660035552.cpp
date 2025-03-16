#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to partition the arrays based on the quicksort algorithm
int part(vector<int>& a, vector<int>& b, int l, int r) {
    int i = l - 1;
    int j = r;
    int x = b[r];

    while (true) {
        while (b[++i] < x);
        while (i < --j && x < b[j]);

        if (i >= j) break;

        swap(a[i], a[j]);
        swap(b[i], b[j]);
    }

    swap(a[i], a[r]);
    swap(b[i], b[r]);
    return i; // Return the index of the pivot
}

// Function to perform quicksort on two arrays
void quicksort(vector<int>& a, vector<int>& b, int n) {
    vector<int> low(n);
    vector<int> high(n);
    int sp = 0;

    low[sp] = 0;
    high[sp] = n - 1;
    sp++;

    while (sp > 0) {
        sp--; // Decrement stack pointer
        int l = low[sp]; // Get the current low index
        int r = high[sp]; // Get the current high index

        if (l >= r) continue;

        int v = part(a, b, l, r);

        if (v - l < r - v) {
            low[sp] = v + 1; // Right side
            high[sp++] = r;
            low[sp] = l; // Left side
            high[sp++] = v - 1;
        } else {
            low[sp] = l; // Left side
            high[sp++] = v - 1;
            low[sp] = v + 1; // Right side
            high[sp++] = r;
        }
    }
}

// Main function to execute the program
int main() {
    int n, m; // Number of intervals and the number of pairs
    cin >> n >> m;

    vector<int> a(m); // Array to hold start points of intervals
    vector<int> b(m); // Array to hold end points of intervals
    int cnt = 0; // Counter for non-overlapping intervals
    int t = 0; // Variable to track the end of the last added interval

    // Read the intervals into arrays a and b
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // Sort the intervals based on their end points using quicksort
    quicksort(a, b, m);

    // Count the maximum number of non-overlapping intervals
    for (int i = 0; i < m; i++) {
        if (t <= a[i]) {
            t = b[i]; // Update the end to the current interval's end
            cnt++; // Increment the count of non-overlapping intervals
        }
    }

    // Output the count of non-overlapping intervals
    cout << cnt << endl;

    return 0; // Exit the program
}

// <END-OF-CODE>
