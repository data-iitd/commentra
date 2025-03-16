#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Partition function to rearrange elements in array 'a' based on values in array 'b'
int part(vector<int>& a, vector<int>& b, int l, int r) {
    int i = l - 1;
    int j = r;
    int x = b[r];

    while (true) {
        while (b[++i] < x);
        while (i < --j && x < b[j]);

        if (i >= j) break;

        // Swap elements in array 'a'
        swap(a[i], a[j]);
        // Swap elements in array 'b'
        swap(b[i], b[j]);
    }

    // Swap elements in array 'a' and 'b' to place pivot in the correct position
    swap(a[i], a[r]);
    swap(b[i], b[r]);
    return i;
}

// Quicksort function to sort arrays 'a' and 'b' based on values in array 'b'
void quicksort(vector<int>& a, vector<int>& b, int n) {
    vector<int> low(n);
    vector<int> high(n);
    int sp = 0;

    // Initialize the stack with the first range to be sorted
    low[sp] = 0;
    high[sp] = n - 1;
    sp++;

    while (sp > 0) {
        sp--;
        int l = low[sp];
        int r = high[sp];

        if (l >= r) continue;

        // Partition the array and get the pivot index
        int v = part(a, b, l, r);

        // Push the sub-ranges onto the stack based on the pivot position
        if (v - l < r - v) {
            low[sp] = v + 1;
            high[sp++] = r;
            low[sp] = l;
            high[sp++] = v - 1;
        } else {
            low[sp] = l;
            high[sp++] = v - 1;
            low[sp] = v + 1;
            high[sp++] = r;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<int> b(m);

    // Read the pairs of integers into arrays 'a' and 'b'
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    // Sort the pairs using the quicksort function
    quicksort(a, b, m);

    // Count the number of unique intervals
    int t = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (t <= a[i]) {
            t = b[i];
            cnt++;
        }
    }

    // Print the count of unique intervals
    cout << cnt << endl;

    return 0;
}

// <END-OF-CODE>
