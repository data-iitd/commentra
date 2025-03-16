

#include <iostream> // Include the standard input/output library

int main(){ // Start of the main function
  int a, b, x, y; // Declare variables a, b, x, and y as integers

  std::cin >> a >> b; // Read two integers from the standard input and store them in variables a and b

  x = a*b; // Multiply the values of variables a and b and store the result in variable x
  y = (a+b)*2; // Add the values of variables a and b, then multiply the result by 2 and store it in variable y

  std::cout << x << " " << y << std::endl; // Print the values of variables x and y to the standard output, followed by a newline character

  return 0; // Indicate that the main function has executed successfully
}

