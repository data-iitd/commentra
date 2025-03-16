
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <cstdio>

int main() {
    // Declare variables for the number of elements (N) and the number of operations (M)
    int N, M;
    scanf("%d %d", &N, &M);

    // Initialize a vector to hold the elements, with a size of 100000
    std::vector<int> L(100000);
    int l;

    // Read N integers from input and store them in the vector L
    for (int i = 0; i < N; i++) {
        scanf("%d", &l);
        L[i] = l;
    }

    // Sort the vector L in ascending order
    std::sort(L.begin(), L.end());

    // Declare an iterator for the vector
    std::vector<int>::iterator itr;

    // Perform M operations to modify the vector L
    for (int i = 0; i < M; i++) {
        // Get the maximum element from the end of the sorted vector
        int max_L = L.back();
        
        // If the maximum element is 0, break the loop as no further operations are needed
        if (max_L == 0) {
            break;
        }

        // Halve the maximum element
        max_L /= 2;

        // Find the position to insert the halved value in the sorted vector
        itr = std::lower_bound(L.begin(), L.end(), max_L);
        
        // Insert the halved value into the vector at the found position
        L.insert(itr, max_L);
        
        // Remove the last element (the original maximum) from the vector
        L.pop_back();
    }

    // Calculate the sum of all elements in the vector L
    long long ans = std::accumulate(L.begin(), L.end(), 0LL);

    // Output the final sum
    printf("%lld\n", ans);

    return 0;
}
