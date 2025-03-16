#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define the number of elements in the list 'A'
    int N;
    cin >> N;

    // Initialize a vector of pairs to store index and value
    vector<pair<int, int>> A(N);

    // Read the values and store them in the vector along with their indices
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        A[i] = make_pair(i + 1, x);
    }

    // Sort the vector 'A' based on the second element of each pair (the value)
    sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    // Extract the first element (index) of each pair in 'A' into a new vector 'A__'
    vector<int> A__;
    for (const auto& a : A) {
        A__.push_back(a.first);
    }

    // Iterate through the vector 'A__' (excluding the last element) and print each index
    for (size_t i = 0; i < A__.size() - 1; ++i) {
        cout << A__[i] << ' ';
    }

    // Print the last index in 'A__'
    cout << A__.back() << endl;

    return 0;
}

// <END-OF-CODE>
