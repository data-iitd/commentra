#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
#include <algorithm> // Including the algorithm library for sorting

using namespace std; // Using the standard namespace

int main() {
    int n; // Variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from user input
    vector<int> a(n); // Creating a vector of integers of size n

    // Initializing the vector with user input
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Reading an integer value from user input and storing it in the vector at the current index
    }

    sort(a.begin(), a.end()); // Sorting the vector in ascending order using the sort() function

    int min = a[0]; // Assigning the minimum value in the vector to the min variable

    // Checking if all the elements in the vector are multiples of the minimum value
    for (int value : a) {
        if (value % min != 0) { // Checking if the current element is not a multiple of the minimum value
            cout << -1 << endl; // Printing -1 if any non-multiple of the minimum value is found
            return 0; // Exiting the program if any non-multiple of the minimum value is found
        }
    }

    // Printing the minimum value if all elements are multiples of the minimum value
    cout << min << endl;

    return 0; // Returning 0 to indicate successful completion of the program
}

// <END-OF-CODE>
