#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library to use dynamic arrays
#include <algorithm> // Including the algorithm library for sorting

using namespace std; // Using the standard namespace

int main() {
    int n; // Variable to store the number of elements
    cin >> n; // Reading the number of elements from standard input
    vector<int> array(3 * n); // Creating a vector of size 3 times the number of elements

    // Initializing the vector with input values
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i]; // Reading each element into the vector
    }

    // Sorting the vector in ascending order
    sort(array.begin(), array.end());

    int head = array.size() - 2; // Index of the last element to be considered in the current iteration
    long long res = 0; // Result variable to store the sum of the last two elements in each subarray

    // Calculating the sum of the last two elements in each subarray of size n and adding it to the result
    for (int i = 0; i < n; i++) {
        res += array[head]; // Adding the last element of the current subarray to the result
        head -= 2; // Decreasing the index of the last element by 2 to consider the next subarray
    }

    // Printing the result
    cout << res << endl; // Outputting the result

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
