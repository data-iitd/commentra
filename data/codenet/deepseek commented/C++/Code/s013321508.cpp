#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
#include <cstdio>

using namespace std;

int main() {

    int N, M;
    cin >> N >> M; // Reading two integers, N and M.

    vector<int> L(100000); // Initializing a vector L with a size of 100,000.
    int l;
    for (int i = 0; i < N; i++) {
        scanf("%d", &l); // Reading N integers and populating the vector L.
        L[i] = l;
    }

    sort(L.begin(), L.end()); // Sorting the vector L in ascending order.

    vector<int>::iterator itr; // Declaring an iterator for the vector L.
    
    for (int i = 0; i < M; i++) { // Performing M operations.
        int max_L = L.back(); // Finding the largest element in the list.
        if (max_L == 0) {
            break; // If the largest element is 0, break the loop.
        }

        max_L /= 2; // Halving the largest element.
        itr = lower_bound(L.begin(), L.end(), max_L); // Finding the position to insert the halved value.
        L.insert(itr, max_L); // Inserting the halved value back into the list.
        L.pop_back(); // Removing the largest element from the list.
    }

    long long ans = accumulate(L.begin(), L.end(), 0LL); // Calculating the sum of all elements in the list L.

    cout << ans << '\n'; // Printing the result.

}
