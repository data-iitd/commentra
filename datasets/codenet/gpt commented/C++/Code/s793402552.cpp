#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>

typedef long long ll; // Define a long long type alias for convenience
using namespace std;

int main()
{
    // Read two integers a and b from input
    int a, b; 
    cin >> a >> b;

    // Convert b to string to determine its length
    string bstr = to_string(b);
    
    // Calculate the number formed by concatenating a and b
    int num = a * pow(10, bstr.length()) + b;

    // Initialize a variable to find the square root of num
    int i;
    // Loop to check if there exists an integer i such that i*i equals num
    for (i = 1; i <= 100100; i++)
    {
        if (i * i == num) break; // If found, exit the loop
    }

    // Check if a valid integer i was found within the range
    if (i > 100100) 
        cout << "No" << endl; // If no such i exists, print "No"
    else 
        cout << "Yes" << endl; // If such i exists, print "Yes"
}
