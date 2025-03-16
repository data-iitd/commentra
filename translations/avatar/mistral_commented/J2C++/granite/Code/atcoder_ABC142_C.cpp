
#include <iostream> // Importing the C++ I/O Stream Library for using cout and cin
#include <map> // Importing the C++ Map Library for using std::map
#include <vector> // Importing the C++ Vector Library for using std::vector

using namespace std; // Using the standard namespace for using cout and cin

int main() { // Main function declaration
    int N; // Declaring an integer variable 'N' to store the number of elements

    // Reading the number of elements from the user input
    cin >> N;

    map<int, int> idorder; // Declaring and initializing a map 'idorder'

    // Reading the elements and storing their corresponding indices in the map
    for (int i = 1; i <= N; i++) {
        int A; // Declaring an integer variable 'A' to store the current element
        cin >> A; // Reading an element 'A' from the user input
        idorder[A] = i; // Storing the index 'i' of the element 'A' in the map
    }

    // Printing the indices of the elements in the order they were read
    for (int i = 1; i <= N; i++) {
        cout << idorder[i] << " "; // Printing the index of the current element
    }

    return 0; // Returning 0 to indicate successful program execution
}

