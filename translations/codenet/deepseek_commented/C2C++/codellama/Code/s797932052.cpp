#include<iostream>

int main(void)
{
  int a,b; // Declare two integer variables to store user input
  std::cin >> a; // Read an integer value from the user and store it in variable a
  std::cin >> b; // Read another integer value from the user and store it in variable b
  if((a*b)%2 == 0){ // Check if the product of a and b is even or odd
    std::cout << "Even\n"; // Print "Even" if the product is even
  }else{
    std::cout << "Odd\n"; // Print "Odd" if the product is odd
  }
  return 0; // Return 0 to indicate successful execution of the program
}

