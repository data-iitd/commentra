
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <cstdio>

int main() {

    int N, M;
    scanf("%d %d", &N, &M); // Reading two integers, N and M.

    int *L = (int *)malloc(sizeof(int) * N); // Dynamically allocating memory for the array L.
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]); // Reading N integers and populating the array L.
    }

    std::sort(L, L + N); // Sorting the array L in ascending order.

    int max_L;
    for (int i = 0; i < M; i++) { // Performing M operations.
        max_L = L[N - 1]; // Finding the largest element in the array L.
        if (max_L == 0) {
            break; // If the largest element is 0, break the loop.
        }

        max_L /= 2; // Halving the largest element.
        L[N - 1] = max_L; // Assigning the halved value back to the largest element.
        std::nth_element(L, L + N - 1, L + N); // Rearranging the array L to maintain its sorted order.
    }

    long long ans = std::accumulate(L, L + N, 0LL); // Calculating the sum of all elements in the array L.

    printf("%lld\n", ans); // Printing the result.

    free(L); // Freeing the dynamically allocated memory for the array L.

    return 0;
}
