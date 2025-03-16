#include<iostream> // Step 1: Include the standard input/output library.

using namespace std; // Step 2: Use the standard namespace.

int main(){ // Step 3: Define the main function.
        int a,b,ar,le; // Step 4: Declare integer variables a, b, ar, and le.
        cin>>a>>b; // Step 5: Read two integers from the user.
        ar=a*b; // Step 6: Calculate the area of a rectangle (ar) by multiplying a and b.
        le=2*(a+b); // Step 7: Calculate the perimeter of a rectangle (le) by doubling the sum of a and b.
        cout<<ar<<' '<<le<<endl; // Step 8: Print the area and perimeter.
        return 0; // Step 9: Return 0 to indicate successful execution.
}
