#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read an integer input from the user
    int N;
    cin >> N;

    // Read 5 integer inputs from the user and store them in a vector A
    vector<int> A(5);
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    // Calculate the minimum value from the vector A, divide N by this minimum value,
    // take the ceiling of the result, and add 4 to it before printing the final result
    cout << ceil(N / *min_element(A.begin(), A.end())) + 4 << endl;

    return 0;
}

