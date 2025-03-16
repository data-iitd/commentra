

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;  // Taking an integer input N, which represents the number of elements.
    vector<int> V(N);  // Creating a vector named V with N elements.
    for (int i = 0; i < N; i++) {
        cin >> V[i];  // Taking the first line of space-separated integers and storing them in vector V.
    }
    vector<int> C(N);  // Creating a vector named C with N elements.
    for (int i = 0; i < N; i++) {
        cin >> C[i];  // Taking the second line of space-separated integers and storing them in vector C.
    }

    int ans = 0;
    int X = 0;
    int Y = 0;

    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            X = V[i];  // Assigning the i-th element of V to X.
            Y = C[i];  // Assigning the i-th element of C to Y.
            ans += X - Y;  // Adding the difference X - Y to ans.
        }
    }

    cout << ans << endl;  // Printing the value of ans.

    return 0;
}

