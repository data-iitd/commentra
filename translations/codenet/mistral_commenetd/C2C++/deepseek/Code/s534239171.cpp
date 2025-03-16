#include <iostream> // Include iostream library for input/output operations

int main() { // Beginning of main function

 int a, b, n; // Declare and initialize three integer variables

 std::cout << "Enter two integers: "; // Prompt user to enter two integers
 std::cin >> a >> b; // Read two integers from standard input and store in variables a and b

 n = (a + b) / 2; // Calculate the average of a and b and store the result in variable n

 std::cout << "The average of " << a << " and " << b << " is: " << n << std::endl; // Display the average on standard output

 return 0; // Program has executed successfully, return integer value 0 to operating system
}

