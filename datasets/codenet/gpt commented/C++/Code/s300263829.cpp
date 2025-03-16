#include<iostream> // Include the iostream library for input and output operations
using namespace std; // Use the standard namespace to avoid prefixing std:: before standard functions

int main() // Main function where the execution of the program begins
{
  int a, b; // Declare two integer variables a and b to store user input
  
  // Prompt the user to enter two integers
  cout << "Enter two integers: "; 
  cin >> a >> b; // Read two integers from user input and store them in variables a and b
  
  // Calculate the product of a and b and display the result
  cout << "The product is: " << a * b << endl; 
  
  return 0; // Return 0 to indicate that the program ended successfully
}
