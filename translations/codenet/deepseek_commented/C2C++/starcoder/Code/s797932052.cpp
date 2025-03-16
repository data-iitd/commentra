#include<iostream>

using namespace std;

int main(void)
{
  int a,b; // Declare two integer variables to store user input
  cin>>a; // Read an integer value from the user and store it in variable a
  cin>>b; // Read another integer value from the user and store it in variable b
  if((a*b)%2 == 0){ // Check if the product of a and b is even or odd
    cout<<"Even"<<endl; // Print "Even" if the product is even
  }else{
    cout<<"Odd"<<endl; // Print "Odd" if the product is odd
  }
  return 0; // Return 0 to indicate successful execution of the program
}

