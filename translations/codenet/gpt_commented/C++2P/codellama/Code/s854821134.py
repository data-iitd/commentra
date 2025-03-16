#include<iostream>   # Include the input-output stream library
#include<algorithm>  # Include the algorithm library (not used in this code)
#include<queue>      # Include the queue library (not used in this code)
#include<string>     # Include the string library (not used in this code)
#include<vector>     # Include the vector library (not used in this code)
using namespace std; # Use the standard namespace

const int INF = 200000005 # Define a constant INF (not used in this code)

int main()
{
    int a, b; # Declare two integer variables a and b
    cin >> a >> b; # Read two integer inputs from the user

    # Check if both a and b are less than or equal to 8
    if (a <= 8 and b <= 8):
        print("Yay!") # If true, print "Yay!"
    else:
        print(":(") # If false, print ":("

    return 0 # Return 0 to indicate successful execution
}

