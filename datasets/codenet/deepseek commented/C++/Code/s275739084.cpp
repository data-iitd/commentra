#include<iostream> // Include the iostream library for input and output operations.
using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'.
int main() // The main function is the entry point of the program.
{
  int A,B; // Declare two integer variables A and B.
  cin>>A>>B; // Take input from the user for variables A and B.
  int C=A+B; // Calculate the sum of A and B and store it in variable C.
  if(A%3!=0 && B%3!=0 && C%3!=0) // Check if neither A, B, nor the sum C is divisible by 3.
    {
      cout<<"Impossible"<<endl; // If the condition is true, print "Impossible" to the console.
    }else{
    cout<<"Possible"<<endl; // Otherwise, print "Possible" to the console.
  }
  return 0; // Return 0 to indicate successful execution.
}