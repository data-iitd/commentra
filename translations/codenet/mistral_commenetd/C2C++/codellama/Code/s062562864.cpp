
#include<iostream>
// Include the standard input output library

using namespace std;
// Declare the namespace std

int main(){
// Declare the main function

int a,b,c,d,i,j;
// Declare variables a, b, c, d, i, and j

cin>>a>>b>>c>>d;
// Read four integers from the standard input and store them in variables a, b, c, and d

i=a*b;
// Multiply variables a and b and store the result in variable i

j=c*d;
// Multiply variables c and d and store the result in variable j

if(i>j){
// Check if the value of i is greater than j

    cout<<i<<endl;
// If true, print the value of i

}
else{
// If the condition in the if statement is false

    cout<<j<<endl;
// Print the value of j
}

return 0;
// End the main function with a return value of 0
}

