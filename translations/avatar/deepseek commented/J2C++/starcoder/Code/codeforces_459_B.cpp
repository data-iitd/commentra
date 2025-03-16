#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the size of the array
    int N;
    cin >> N;

    // Read the elements of the array
    int A[N];
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }

    // Sort the array
    sort(A, A + N);

    // Find the minimum and maximum values in the array
    int min = A[0];
    int max = A[N - 1];

    // Count the occurrences of the minimum and maximum values
    long mins = 0;
    long maxs = 0;
    for (int value : A) {
        if (value == min) mins++;
        if (value == max) maxs++;
    }

    // Special case: if min == max
    if (min == max) {
        cout << (max - min) << " " << mins * (mins - 1) / 2 << endl;
    } else {
        // General case: if min!= max
        cout << (max - min) << " " << mins * maxs << endl;
    }

    return 0;
}

