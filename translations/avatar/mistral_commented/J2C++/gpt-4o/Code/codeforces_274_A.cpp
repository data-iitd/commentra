#include <iostream> // Including the iostream library for input and output
#include <vector>   // Including the vector library to use the vector container
#include <set>      // Including the set library to use the set container
#include <algorithm> // Including the algorithm library for sorting

using namespace std; // Using the standard namespace

int main() { // Defining the main function
    int n; // Variable to store the number of elements
    long long k; // Variable to store the long integer value k

    cin >> n; // Reading the first integer value n from standard input
    cin >> k; // Reading the long integer value k from standard input

    vector<long long> arr(n); // Creating a vector named arr of length n to store long integer values
    set<long long> uniqueSet; // Creating an empty set named uniqueSet to store unique long integer values

    for (int i = 0; i < n; i++) { // Iterating through the vector arr from index 0 to n-1
        cin >> arr[i]; // Reading a long integer value from standard input and storing it in arr[i]
    }

    sort(arr.begin(), arr.end()); // Sorting the arr vector in ascending order using the sort() function

    int count = 0; // Initializing the count variable to 0

    for (int i = 0; i < n; i++) { // Iterating through the sorted arr vector from index 0 to n-1
        if (arr[i] % k != 0) { // Checking if the arr[i] value is not divisible by k
            count++; // Incrementing the count variable if the condition is true
            uniqueSet.insert(arr[i]); // Adding the arr[i] value to the set if it is not already present
        } else if (uniqueSet.find(arr[i] / k) == uniqueSet.end()) { // Checking if arr[i] is divisible by k and if its quotient is not present in the set
            count++; // Incrementing the count variable if the condition is true
            uniqueSet.insert(arr[i]); // Adding the arr[i] value to the set if it is not already present
        }
    }

    cout << count << endl; // Printing the count value to the standard output
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
