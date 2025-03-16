#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library for using dynamic arrays
#include <sstream>  // Including the sstream library for string stream operations

using namespace std; // Using the standard namespace

int main() { // Starting the main function
    int n; // Declaring an integer variable for the number of elements
    cin >> n; // Reading the number of elements from standard input
    vector<int> arr(n); // Creating a vector of integers of size n
    int sum = 0; // Initializing the sum variable to 0

    for (int i = 0; i < n; i++) { // Starting a for loop to read and store the elements in the array
        cin >> arr[i]; // Reading an integer value from standard input and storing it in the current index of the array
        sum += arr[i]; // Adding the current element to the sum variable
    }

    int c = 0; // Initializing the counter variable to 0
    stringstream ss; // Creating a string stream object to store the indices of the elements that satisfy the condition

    for (int i = 0; i < n; i++) { // Starting a for loop to check if an element satisfies the condition
        if ((sum - arr[i]) % (n - 1) == 0 && (sum - arr[i]) / (n - 1) == arr[i]) { // Checking if the current element satisfies the condition
            c++; // Incrementing the counter variable if the condition is true
            ss << (i + 1) << " "; // Appending the index of the current element to the string stream
        }
    }

    cout << c << endl; // Printing the number of elements that satisfy the condition
    cout << ss.str() << endl; // Printing the indices of the elements that satisfy the condition separated by a space

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
