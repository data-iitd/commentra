/

#include <bits/stdc++.h>
using namespace std;

// Function to read input from stdin
void read_input(int a[], int n, int k) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

// Function to write output to stdout
void write_output(int ans) {
    cout << ans << endl;
}

// Function to sort the array a in parallel using parallel sort
void parallel_sort(int a[], int n) {
    // Sort the array a in parallel using parallel sort
    sort(a, a + n);
}

// Function to calculate the answer: sum of first k elements of sorted array a
int calculate_answer(int a[], int n, int k) {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += a[i];
    }
    return ans;
}

// Main function to start the program
int main() {
    // Read input: number of elements n and the number of summands k
    int n, k;
    cin >> n >> k;

    // Read input array a of size n
    int a[n];
    read_input(a, n, k);

    // Sort the array a in parallel using parallel sort
    parallel_sort(a, n);

    // Calculate the answer: sum of first k elements of sorted array a
    int ans = calculate_answer(a, n, k);

    // Write the answer to the output stream
    write_output(ans);

    return 0;
}

