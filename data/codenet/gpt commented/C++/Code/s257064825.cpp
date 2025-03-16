#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
using namespace std;

// Define 'int' as 'long long int' for larger integer support
#define int long long int

int32_t main()
{
    // Optimize input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // Declare a string to hold the input
    string str;
    // Read the input string from the user
    cin >> str;
    
    // Initialize a variable to hold the sum of digits
    int sum = 0;
    
    // Iterate through each character in the string
    for(char x : str)
    {
        // Convert character to integer and add to sum
        sum += (x - 48); // '48' is the ASCII value of '0'
    }
    
    // Check if the sum of digits is divisible by 9
    if(sum % 9 == 0)
    {
        // If divisible, print "Yes"
        cout << "Yes" << endl;
    }
    else
    {
        // If not divisible, print "No"
        cout << "No" << endl;
    }
}
