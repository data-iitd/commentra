#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a scanner object to read input from the console
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    sort(L.begin(), L.end());
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a = L[i];
            int b = L[j];
            int res = find(L, j + 1, a + b);
            count = count + res;
        }
    }
    cout << count << "\n";
}

// Method to find the count of integers in the list that can form a valid triplet
int find(vector<int> li, int from, int target) {
    int low = from;
    int upp = li.size() - 1;
    // Calculate the mid index based on the current low and upper bounds
    int mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    // Base cases for the search
    if (upp - low < 0) {
        return 0;
    } else if (li[from] >= target) {
        return 0;
    } else if (li[upp] < target) {
        return upp - low + 1;
    }
    // Perform binary search to find the count of valid integers
    while (upp - low > 1) {
        if (li[mid] >= target) {
            upp = mid;
        } else {
            low = mid;
        }
        // Update mid index after adjusting low and upp
        mid = (upp - low + 1) % 2 == 0? (low + upp) / 2 + 1 : (low + upp) / 2;
    }
    // Return the count of valid integers found
    return low - from + 1;
}

