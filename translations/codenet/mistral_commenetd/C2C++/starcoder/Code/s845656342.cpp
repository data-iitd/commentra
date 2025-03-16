#include <iostream>  // Include the standard input/output library
#include <cstdlib>   // Include the standard library for memory allocation
#include <cmath>     // Include the math library for square root calculation

using namespace std;  // Use the standard namespace

int main(void)  // The main function is the entry point of the program
{
  int x;          // Declare an integer variable named x

  // Read an integer value from the standard input and store it in the variable x
  cin >> x;

  if(x==1)  // Check if the value of x is equal to 1
  {
    cout << "0" << endl;  // If x is 1, print 0 to the standard output
  }
  else  // If x is not equal to 1
  {
    cout << "1" << endl;  // Otherwise, print 1 to the standard output
  }

  return 0;  // Indicate that the program has run successfully and terminate
}

