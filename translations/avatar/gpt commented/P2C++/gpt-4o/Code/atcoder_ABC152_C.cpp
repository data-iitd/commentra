#include <iostream>  // Including the iostream library for input and output
#include <vector>   // Including the vector library for dynamic arrays

int main() {
    int N;  // Variable to store the number of elements
    std::cout << "Enter the number of elements: ";  // Prompting for input
    std::cin >> N;  // Taking input for the number of elements

    std::vector<int> n(N);  // Creating a vector to store the elements

    std::cout << "Enter the elements separated by spaces: ";  // Prompting for elements
    for (int i = 0; i < N; ++i) {
        std::cin >> n[i];  // Taking input for each element
    }

    int a = 1;  // Initializing a counter 'a' to count the number of elements that are less than the current element
    int pos = 0;  // Initializing 'pos' to keep track of the position of the last element that was smaller

    // Looping through the array starting from the second element
    for (int i = 1; i < N; ++i) {
        // Checking if the current element is smaller than the element at 'pos'
        if (n[pos] > n[i]) {
            a++;  // Incrementing the counter if the condition is met
            pos = i;  // Updating 'pos' to the current index
        }
    }

    // Printing the final count of elements that were smaller than the previous ones
    std::cout << a << std::endl;

    return 0;  // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
