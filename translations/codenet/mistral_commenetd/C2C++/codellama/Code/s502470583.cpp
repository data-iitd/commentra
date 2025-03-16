
#include<iostream> // Include the standard input/output library

using namespace std; // Use the standard namespace

int main( ){ // Start of the main function
  int a, b, c, d; // Declare four integer variables a, b, c, and d

  // Read two integers from the user and store them in variables a and b
  cin>>a>>b;

  // Multiply the two integers and store the result in variable c
  c=a*b;

  // Multiply each integer with 2 and add them to get the value of d
  d=2*a+2*b;

  // Print the values of c and d on the console
  cout<<c<<" "<<d<<endl;

  // End of the main function and return 0 to indicate successful execution
  return 0;
}

