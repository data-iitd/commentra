#include<iostream>  // Include the standard input-output library
using namespace std;  // Use the standard namespace
int main()        // Define the main function, the entry point of the program
{
    int a,b,c;     // Declare three integer variables
    cin>>a>>b>>c;  // Read three integer inputs from the user and store them in a, b, and c
    if(a<b&&b<c)  // Check if a is less than b and b is less than c
    {
        cout<<"Yes\n";  // If true, print "Yes"
    }
    else  // Otherwise
    {
        cout<<"No\n";  // Print "No"
    }
    return 0;  // Return 0 to indicate successful execution
}
