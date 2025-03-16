
#include <iostream>
using namespace std;

int main()
{
    int A, B; // Declare two integer variables A and B
    cin>>A>>B; // Read the values of A and B from the standard input

    if(A<13 && A>=6){ // Check if A is within the range of 6 to 12 (inclusive)
        cout<<B/2<<endl; // If true, divide B by 2 and print the result to the standard output
    }

    if(A<6){ // Check if A is less than 6
        cout<<0<<endl; // If true, print 0 to the standard output
    }

    if(A>=13){ // Check if A is greater than or equal to 13
        cout<<B<<endl; // If true, print B to the standard output
    }

    return 0;
}