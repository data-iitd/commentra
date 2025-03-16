#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the standard input stream
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(ios::badbit);
    Scanner in(0);

    // Create a PrintWriter object to output results to the standard output stream
    cout.sync_with_stdio(0);
    cout.tie(0);
    cout.exceptions(ios::badbit);
    PrintWriter pw(0);

    // Read the number of elements from input
    int N = in.nextInt();

    // Initialize an array to hold the input integers
    int A[N];

    // Read N integers from input and store them in the array A
    for (int n = 0; n < N; n++) {
        A[n] = in.nextInt();
    }

    // Sort the array A to easily find the minimum and maximum values
    sort(A);

    // Identify the minimum and maximum values in the sorted array
    int min = A[0];
    int max = A[N - 1];

    // Initialize counters for occurrences of min and max values
    long mins = 0;
    long maxs = 0;

    // Count how many times the minimum and maximum values occur in the array
    for (int value : A) {
        if (value == min) mins++;
        if (value == max) maxs++;
    }

    // If all elements are the same (min equals max)
    if (min == max) {
        // Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        pw.println((max - min) + " " + mins * (mins - 1) / 2);
    } else {
        // Calculate the difference and the product of occurrences of min and max
        pw.println((max - min) + " " + mins * maxs);
    }

    // Close the PrintWriter to flush the output
    pw.close();

    return 0;
}

