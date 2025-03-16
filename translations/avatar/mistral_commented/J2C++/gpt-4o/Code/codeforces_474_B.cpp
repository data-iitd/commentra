#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays
#include <algorithm> // Including the algorithm library for binary search

using namespace std;

int fun(const vector<int>& arr, int q, int n, int m) {
    int res = 0; // Initializing a variable to store the result
    int i = 0, j = n; // Initializing two variables to represent the left and right indices of the array

    // Using a while loop to perform a binary search on the array
    while (i <= j) {
        int md = i + (j - i) / 2; // Calculating the middle index of the subarray
        if (arr[md] == q) { // If the middle element is equal to the query, return the middle index
            return md;
        } else if (arr[md] > q) { // If the middle element is greater than the query, update the result and shift the right index towards the left
            res = md;
            j = md - 1;
        } else { // If the middle element is less than the query, shift the left index towards the right
            i = md + 1;
        }
    }

    // If the query is not present in the array, return the index where it should be inserted
    return res;
}

int main() {
    int n;
    cin >> n; // Reading the number of elements in the array from the input
    vector<int> arr(n); // Creating a vector of size n
    cin >> arr[0]; // Reading the first element of the array from the input

    // Initializing a for loop to read and store the remaining elements of the array
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x; // Reading an element from the input
        arr[i] = x + arr[i - 1]; // Assigning the current element the sum of the previous element and the current input
    }

    int m;
    cin >> m; // Reading the number of queries from the input
    vector<int> q(m); // Creating a vector of size m to store the queries

    // Initializing a for loop to read and store the queries in the vector q
    for (int i = 0; i < m; i++) {
        cin >> q[i]; // Reading a query from the input
    }

    // Initializing a for loop to process each query and print the result
    for (int k = 0; k < m; k++) {
        cout << fun(arr, q[k], n, m) + 1 << endl; // Calling the fun function with the array, query, size of the array, and number of queries as arguments and printing the result with an offset of 1
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
