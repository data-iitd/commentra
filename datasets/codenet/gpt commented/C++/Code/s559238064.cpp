#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

// Define long long type for large integers
typedef long long ll;

// Constants for infinity and modulo operations
const int inf = 0x3f3f3f3f;
const int mod = (1 ? 1e9 + 7 : 998244353);

int main()
{
    // Optimize input/output operations
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    // Declare variables for input and processing
    ll a, b, c, d, e, f, g, T;
    string z;
    
    // Read the input string
    cin >> z;
    
    // Get the size of the input string
    a = z.size();
    
    // Check for consecutive identical characters in the string
    for (int i = 0; i < a - 1; i++)
    {
        // If two consecutive characters are the same, print "Bad" and exit
        if (z[i] == z[i + 1])
        {
            cout << "Bad" << endl;
            return 0;
        }
    }
    
    // If no consecutive identical characters were found, print "Good"
    cout << "Good" << endl;
}
