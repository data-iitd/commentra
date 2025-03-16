#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Create a HashMap to map each value in P to its index
    map<int, int> map;
    for (int i = 0; i < N; ++i) {
        map[P[i]] = i;
    }

    // Create a list to store indices of elements that are out of order
    vector<int> nglist;
    for (int i = 0; i < N - 1; ++i) {
        if (map[P[i]] > map[P[i + 1]]) {
            nglist.push_back(i); // Add the index to nglist if the current element is greater than the next element
        }
    }

    // If nglist is empty, the array P is already sorted
    if (nglist.empty()) {
        cout << 0 << endl; // Print 0 and return as the array is sorted
        return 0;
    }

    // Calculate the minimum number of swaps required to sort the array P
    int ans = min(N - nglist[0] - 1, nglist[nglist.size() - 1] + 1);
    for (int i = 0; i < nglist.size() - 1; ++i) {
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans);
    }

    // Print the minimum number of swaps required
    cout << ans << endl;
}

