#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Input the number of elements (N)
    int N;
    cin >> N;

    // Input the elements and create a vector of pairs
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        A[i] = make_pair(i + 1, x);
    }

    // Sort the vector of pairs based on the integer values
    sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // Extract the indices from the sorted vector of pairs
    vector<int> A_indices(N);
    for (int i = 0; i < N; ++i) {
        A_indices[i] = A[i].first;
    }

    // Print the indices in the required format
    for (int i = 0; i < N - 1; ++i) {
        cout << A_indices[i] << " ";
    }
    cout << A_indices[N - 1] << endl;

    return 0;
}

// <END-OF-CODE>
