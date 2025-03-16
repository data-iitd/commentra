
#include <iostream> // Importing the iostream library for input and output

using namespace std; // Using the standard namespace

int main() {
    int n; // Declaring the variable n to store the number of elements in the array
    cout << "Enter the number of elements in the array: "; // Prompt the user to enter the number of elements
    cin >> n; // Read the number of elements from the user input

    int array[n + 1]; // Initializing an array of size n+1

    // Populating the array with integers from the user input
    for (int i = 1; i <= n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> array[i];
    }

    int odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Initializing variables to count odd and even numbers and their indices

    // Counting the number of odd and even numbers and recording their indices
    for (int i = 1; i <= n; i++) {
        if (array[i] % 2 == 0) {
            even++;
            even_ind = i;
        } else {
            odd++;
            odd_ind = i;
        }
    }

    // Comparing the counts of odd and even numbers and printing the index of the majority
    if (odd > even) {
        cout << "The index of the majority number is: " << even_ind << endl;
    } else {
        cout << "The index of the majority number is: " << odd_ind << endl;
    }

    return 0; // Returning 0 to indicate successful execution of the program
}
