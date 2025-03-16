
#include <iostream> // Importing the iostream library for input/output operations

using namespace std; // Using the standard namespace for iostream

int main() {
    int n; // Declaring an integer variable to store the number of elements in the array
    cin >> n; // Reading the number of elements from the user using cin
    
    int array[n + 1]; // Initializing an array of size n + 1 to store the input integers
    
    for (int i = 1; i <= n; i++) {
        cin >> array[i]; // Reading n integers from the user and storing them in the array
    }
    
    int odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Initializing counters for odd and even numbers and their latest indices
    
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) { // Checking if the number is even
            even++; // Incrementing the even counter
            even_ind = i; // Updating the index of the last even number
        } else { // The number is odd
            odd++; // Incrementing the odd counter
            odd_ind = i; // Updating the index of the last odd number
        }
    }
    
    if (odd > even) {
        cout << even_ind << endl; // Print the index of the last even number if there are more odds
    } else {
        cout << odd_ind << endl; // Print the index of the last odd number otherwise
    }
    
    return 0; // Returning 0 to indicate successful program execution
}

