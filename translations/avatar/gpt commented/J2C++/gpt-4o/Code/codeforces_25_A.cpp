#include <iostream> // Including the iostream library for input and output
using namespace std;

int main() {
    // Reading the number of elements in the array
    int n;
    cin >> n;

    // Initializing an array of size n + 1 to store the input integers
    int array[n + 1];

    // Loop to read n integers from the user and store them in the array
    for (int i = 1; i <= n; i++) {
        cin >> array[i]; // Storing each integer in the array
    }

    // Initializing counters for odd and even numbers and their latest indices
    int odd = 0, even = 0, odd_ind = 0, even_ind = 0;

    // Loop to count odd and even numbers and track their latest indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) { // Checking if the number is even
            even++; // Incrementing the even counter
            even_ind = i; // Updating the index of the last even number
        } else { // The number is odd
            odd++; // Incrementing the odd counter
            odd_ind = i; // Updating the index of the last odd number
        }
    }

    // Comparing the counts of odd and even numbers to determine which index to print
    if (odd > even) {
        cout << even_ind << endl; // Print the index of the last even number if there are more odds
    } else {
        cout << odd_ind << endl; // Print the index of the last odd number otherwise
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
