
#include<iostream> // Include standard input/output library

using namespace std; // Declare namespace

int main(void){ // Beginning of main function

 int a, b, n; // Declare and initialize three integer variables

 cout<<"Enter two integers: "; // Prompt user to enter two integers
 cin>>a>>b; // Read two integers from standard input and store in variables a and b

 n=(a+b)/2; // Calculate the average of a and b and store the result in variable n

 cout<<"The average of "<<a<<" and "<<b<<" is: "<<n<<endl; // Display the average on standard output

 return 0; // Program has executed successfully, return integer value 0 to operating system
}

