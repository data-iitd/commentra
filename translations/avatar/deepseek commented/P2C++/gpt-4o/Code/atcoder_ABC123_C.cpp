#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N; // Step 2: Read an integer input N which represents some quantity or value.

    vector<int> A(5);
    for (int i = 0; i < 5; ++i) {
        cin >> A[i]; // Step 3: Read five integer inputs and store them in a vector A.
    }

    int min_value = *min_element(A.begin(), A.end()); // Find the minimum value in A.
    cout << ceil(static_cast<double>(N) / min_value) + 4 << endl; // Step 4: Calculate and print the result.

    return 0;
}

// <END-OF-CODE>
