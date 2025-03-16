
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <cstdio>

using namespace std;

// Main function starts here
int main() {

    int N, M; // Initialize two integers to read input from user

    // Read input from user
    cin >> N >> M ;

    // Initialize a vector of integers with size N
    vector<int> L(N);

    // Read integers from user and store them in the vector
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]); // Read an integer and store it in the vector
    }

    // Sort the vector in ascending order
    sort(L.begin(), L.end());

    // Iterator to traverse the vector
    vector<int>::iterator itr;

    // Perform the required operations for M times
    for (int i = 0; i < M; i++) {
        int max_L = L.back(); // Get the last element of the vector

        // If the last element is 0, break the loop
        if (max_L == 0) {
            break;
        }

        // Divide the last element by 2
        max_L /= 2;

        // Find the position of the element greater than or equal to max_L using lower_bound
        itr = lower_bound(L.begin(), L.end(), max_L);

        // Insert max_L before the found position and remove the last element
        L.insert(itr, max_L);
        L.pop_back();
    }

    // Calculate the answer and print it
    long long ans = accumulate(L.begin(), L.end(), 0LL);
    cout << ans << '\n';

}