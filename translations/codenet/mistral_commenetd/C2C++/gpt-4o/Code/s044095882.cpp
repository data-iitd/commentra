#include <iostream>
#include <vector>

int main() {
    long int n; // Declare a variable to store the number of elements in the array

    std::cout << "Enter the number of elements: ";
    std::cin >> n; // Read the number of elements from the standard input and store it in n

    std::vector<long int> a(n); // Declare a vector of size n to store the input numbers
    std::vector<long int> count(n, 0); // Declare a vector of size n to store the count of occurrences of each number, initialized to zero

    std::cout << "Enter " << n << " numbers:\n";
    for (long int i = 0; i < n; i++) { // Initialize the vector a with input numbers
        std::cin >> a[i];
    }

    std::cout << "Counting occurrences:\n";
    for (long int i = 0; i < n; i++) { // Iterate through the vector a and increment the corresponding element in the count vector
        count[a[i] - 1]++;
    }

    std::cout << "Printing the contents of the count array:\n";
    for (long int i = 0; i < n; i++) { // Print the contents of the count vector to the standard output
        std::cout << count[i] << std::endl;
    }

    std::cout << "Program completed successfully." << std::endl;
    return 0; // Return 0 to indicate successful termination
}

// <END-OF-CODE>
