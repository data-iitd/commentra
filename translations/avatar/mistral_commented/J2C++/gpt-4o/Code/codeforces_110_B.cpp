#include <iostream> // Include the iostream library for input and output
#include <vector>   // Include the vector library for dynamic array
using namespace std; // Use the standard namespace

int main() {
    int n; // Declare an integer variable `n` to store the size of the character array
    char p = 'a'; // Declare a character variable `p` to store the current character to be added to the array

    cin >> n; // Read an integer `n` from the standard input
    vector<char> c(n); // Create a new character vector `c` of size `n`

    for (int i = 0; i < 4; i++) { // Use a for loop to iterate through the first four elements of the array
        for (int j = i; j < n; j += 4) { // Use a nested for loop to populate every fourth element of the array with the next character
            c[j] = p; // Set the current element of the array to the current character
            p++; // Increment the character to be added to the next element
        }
    }

    for (int i = 0; i < n; i++) { // Use a for loop to print each character in the array to the standard output
        cout << c[i]; // Print the character
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
