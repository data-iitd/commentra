
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Create a Scanner object to read input from the standard input stream
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    // Create a vector to hold the input integers
    vector<int> A(N);

    // Read N integers from input and store them in the vector A
    for (int n = 0; n < N; n++) {
        cin >> A[n];
    }

    // Sort the vector A to easily find the minimum and maximum values
    sort(A.begin(), A.end());

    // Identify the minimum and maximum values in the sorted vector
    int min = A[0];
    int max = A[N - 1];

    // Initialize counters for occurrences of min and max values
    long long mins = 0;
    long long maxs = 0;

    // Count how many times the minimum and maximum values occur in the vector
    for (int value : A) {
        if (value == min) mins++;
        if (value == max) maxs++;
    }

    // If all elements are the same (min equals max)
    if (min == max) {
        // Calculate the difference (which is 0) and the number of ways to choose 2 from mins
        cout << (max - min) << " " << mins * (mins - 1) / 2 << endl;
    } else {
        // Calculate the difference and the product of occurrences of min and max
        cout << (max - min) << " " << mins * maxs << endl;
    }

    return 0;
}

