#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 
using namespace std; 

int main()
{
    // Declare four integer variables to hold input values
    int a, b, c, d; 

    // Read four integer values from user input
    cin >> a >> b >> c >> d; 

    // Check if the product of a and b is odd and the sum of c and d is odd
    if (a * b % 2 == 1 && (c + d) % 2 == 1)
    {
        // If both conditions are true, output "No"
        cout << "No" << endl;
    }
    else
    {
        // If either condition is false, output "Yes"
        cout << "Yes" << endl;
    }
}
