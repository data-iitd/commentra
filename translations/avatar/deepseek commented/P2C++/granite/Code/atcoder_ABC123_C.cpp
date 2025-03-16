

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    int min_A = *min_element(A.begin(), A.end());
    int result = ceil(N / (double)min_A) + 4;
    cout << result << endl;

    return 0;
}

// Step 1: Include necessary header files for input/output operations, mathematical operations, and data structures.

// Step 2: Read an integer input N which represents some quantity or value.

// Step 3: Read five integer inputs and store them in a vector A. This vector will be used to determine the minimum value among these integers.

// Step 4: Calculate the result by dividing N by the smallest value in A and rounding up to the nearest integer, then add 4 to the result. Finally, print the result.

// 