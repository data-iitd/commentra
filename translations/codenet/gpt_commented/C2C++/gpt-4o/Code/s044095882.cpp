#include <iostream>
#include <vector>

int main() {
    // Declare a variable to hold the size of the array
    long int n;

    // Read the size of the array from user input
    std::cin >> n;

    // Declare two vectors: one to hold the input values and another to count occurrences
    std::vector<long int> a(n);
    std::vector<long int> count(n, 0);

    // Read the input values into the vector 'a', starting from index 1
    for (long int i = 1; i < n; i++)
        std::cin >> a[i];

    // Count the occurrences of each value in the vector 'a'
    // The value at a[i] is used to index into the count vector
    for (long int i = 1; i < n; i++)
        count[a[i] - 1]++;

    // Print the counts of each index in the count vector
    for (long int i = 0; i < n; i++)
        std::cout << count[i] << std::endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

// <END-OF-CODE>
