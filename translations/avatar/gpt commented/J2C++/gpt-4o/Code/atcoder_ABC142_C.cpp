#include <iostream> // Including necessary header for input/output
#include <unordered_map> // Including header for unordered_map
#include <vector> // Including header for vector

using namespace std;

int main() {
    // Creating a variable to hold the number of elements (N)
    int N;
    // Reading the number of elements from the input
    cin >> N;

    // Creating an unordered_map to store the mapping of integer values to their order of input
    unordered_map<int, int> idorder;

    // Looping through the range from 1 to N to read N integers
    for (int i = 1; i <= N; i++) {
        // Reading an integer A from the input
        int A;
        cin >> A;
        // Storing the integer A in the map with its order of input (i)
        idorder[A] = i;
    }

    // Looping through the range from 1 to N to print the order of each integer
    for (int i = 1; i <= N; i++) {
        // Retrieving and printing the order of the integer i from the map
        cout << idorder[i] << " ";
    }

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
