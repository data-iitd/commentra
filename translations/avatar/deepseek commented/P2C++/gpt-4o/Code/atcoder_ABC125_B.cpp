#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;  // Taking an integer input N, which represents the number of elements.
    
    vector<int> V(N);  // Initializing a vector V of size N.
    for (int i = 0; i < N; i++) {
        cin >> V[i];  // Taking the first line of space-separated integers and storing them in vector V.
    }
    
    vector<int> C(N);  // Initializing a vector C of size N.
    for (int i = 0; i < N; i++) {
        cin >> C[i];  // Taking the second line of space-separated integers and storing them in vector C.
    }

    vector<int> list;  // Initializing a vector named list.
    list.push_back(0);  // Adding a single element 0 to the list.
    int ans = 0;
    int X = 0;
    int Y = 0;

    // Entering a for loop that iterates N times.
    for (int i = 0; i < N; i++) {
        // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
        if (V[i] - C[i] > 0) {
            X = V[i];  // Assigning the i-th element of V to X.
            Y = C[i];  // Assigning the i-th element of C to Y.
            list.push_back(X - Y);  // Appending the difference X - Y to the list.
        }
    }

    // Printing the sum of the list.
    int sum = 0;
    for (int value : list) {
        sum += value;  // Calculating the sum of the elements in the list.
    }
    cout << sum << endl;  // Outputting the sum.

    return 0;
}

// <END-OF-CODE>
