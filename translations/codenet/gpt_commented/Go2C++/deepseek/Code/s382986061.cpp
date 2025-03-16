#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> as(N + 1, 0); // Initialize a vector to count occurrences of each element, with size N+1 and initial value 0.

    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            as[a]++; // Increment the count for the element a.
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (as[i] == 0) {
            ans++; // Increment the counter for missing elements.
        }
    }

    cout << ans << endl; // Output the total count of elements that were not present in any group.

    return 0;
}
