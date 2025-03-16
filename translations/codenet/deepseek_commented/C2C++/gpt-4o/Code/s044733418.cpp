#include <iostream>  // Include the iostream library for input/output
#include <algorithm> // Include the algorithm library for sorting
#include <vector>    // Include the vector library for using vectors

// Define a function to compare two integers
bool compare(int a, int b)
{
    return a > b;  // Return true if a is greater than b (for descending order)
}

int main()  // Define the main function
{
    std::vector<int> array(10);  // Declare a vector of 10 integers
    for(int i = 0; i < 10; i++)  // Read 10 integers from the input
        std::cin >> array[i];
    
    std::sort(array.begin(), array.end(), compare);  // Sort the vector using the sort function and the compare function
    
    for(int i = 0; i < 3; i++)  // Print the first three elements of the sorted vector
        std::cout << array[i] << std::endl;
    
    return 0;  // Return 0 to indicate successful execution
}

// <END-OF-CODE>
