#include <iostream> // Including necessary I/O classes
#include <vector>   // Including vector class
#include <algorithm> // Including algorithm for sorting
using namespace std;

int main() {
    int n; // Variable to store the number of elements
    cin >> n; // Reading the number of elements
    vector<int> list(n); // Creating a vector to store the elements
    
    // Reading the elements and adding them to the vector
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    
    sort(list.begin(), list.end()); // Sorting the vector
    
    int c = 1; // Initializing the counter variable
    
    // Iterating through the sorted list to find the smallest missing positive integer
    for (int i = 0; i < n; i++) {
        if (list[i] >= c) {
            c++;
        }
    }
    
    cout << c << endl; // Printing the result
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
