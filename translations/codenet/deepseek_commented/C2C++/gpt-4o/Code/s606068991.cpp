#include <iostream>
#include <vector>

using namespace std;

// Function to print the array elements
void white(int n, const vector<int>& A) {
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;
}

// Function to perform insertion sort on the array
void insertionsort(int n, vector<int>& A) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] < A[j]) {
                // Swap A[i] and A[j]
                swap(A[i], A[j]);
            }
        }
        // Print the array after each insertion
        white(n, A);
    }
}

// Main function to handle input and call the sorting function
int main() {
    int n;
    vector<int> A(100);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    insertionsort(n, A);

    return 0;
}

// <END-OF-CODE>
