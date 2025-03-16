#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(const vector<int>& li, int from, int target) {
    int low = from;
    int upp = li.size() - 1;

    // Base cases for the search
    if (upp < low) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }

    // Perform binary search to find the count of valid integers
    while (upp - low > 1) {
        int mid = (low + upp) / 2;
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
    }

    // Return the count of valid integers found
    return low - from + 1;
}

int main() {
    // Create a vector to store the integers
    int N;
    cin >> N;
    vector<int> L(N);

    // Read N integers from input and add them to the vector
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    // Sort the vector of integers in ascending order
    sort(L.begin(), L.end());

    // Initialize a counter to keep track of valid pairs
    int count = 0;

    // Iterate through each pair of integers in the sorted vector
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // Get the current pair of integers
            int a = L[i];
            int b = L[j];

            // Find the number of integers that can form a valid triplet with a and b
            int res = find(L, j + 1, a + b);

            // Increment the count by the number of valid triplets found
            count += res;
        }
    }

    // Output the total count of valid triplets
    cout << count << endl;

    return 0;
}

// <END-OF-CODE>
