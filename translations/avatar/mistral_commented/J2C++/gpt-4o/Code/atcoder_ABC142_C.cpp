#include <iostream> // Including the iostream library for input and output
#include <unordered_map> // Including the unordered_map for using hash maps
#include <vector> // Including the vector library for using dynamic arrays

using namespace std; // Using the standard namespace

int main() { // Main function declaration
    int N; // Declaring an integer variable 'N' to store the number of elements
    cin >> N; // Reading the number of elements from the user input

    unordered_map<int, int> idorder; // Declaring and initializing an unordered_map 'idorder'

    // Reading the elements and storing their corresponding indices in the unordered_map
    for (int i = 1; i <= N; i++) {
        int A; // Declaring an integer variable 'A'
        cin >> A; // Reading an element 'A' from the user input
        idorder[A] = i; // Storing the index 'i' of the element 'A' in the unordered_map
    }

    // Printing the indices of the elements in the order they were read
    for (int i = 1; i <= N; i++) {
        cout << idorder[i] << " "; // Printing the index of the current element
    }

    cout << endl; // Printing a newline for better output formatting
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
