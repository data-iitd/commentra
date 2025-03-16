#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the input
    vector<int> A;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    // Check if the second or third element of the list 'A' is less than or equal to the first element
    if (A[1] <= A[2] || A[3] <= A[0]) {
        // If the condition is true, print '0'
        cout << 0 << endl;
    } else {
        // If the condition is false, sort the list 'A' in ascending order
        sort(A.begin(), A.end());

        // Print the difference between the third and second elements of the sorted list
        cout << A[2] - A[1] << endl;
    }

    return 0;
}

