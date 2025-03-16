#include<iostream>

using namespace std;

int main(void)
{
  int a, b; // Declare two integer variables 'a' and 'b'
  // Initialize them to zero by default

  cin>>a; // Read an integer value from the standard input and store it in variable 'a'
  cin>>b; // Read an integer value from the standard input and store it in variable 'b'

  if((a*b)%2 == 0){ // Check if the product of 'a' and 'b' is even
    cout<<"Even"<<endl; // If it is even, print "Even" to the standard output
  }else{
    cout<<"Odd"<<endl; // If it is odd, print "Odd" to the standard output
  }

  return 0; // Indicate successful termination of the program
}

