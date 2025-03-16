#include<iostream>  // Include the standard input/output library

int main(){  // Define the main function

    int a, b, n;  // Declare integer variables
    std::cin >> a >> b;  // Read input values
    n = (a + b) / 2;  // Calculate the average
    std::cout << n << std::endl;  // Print the result
    return 0;  // Return from main function
}

