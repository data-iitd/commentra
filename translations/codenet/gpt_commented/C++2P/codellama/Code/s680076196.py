#include <iostream>  # Include the input-output stream library
#include <algorithm> # Include the algorithm library (not used in this code)
#include <cmath>     # Include the cmath library (not used in this code)
using namespace std;

typedef long long ll; # Define 'll' as an alias for 'long long' for convenience

int main():
    int a, b, c, d; # Declare four integer variables to hold input values

    # Read four integer values from standard input
    cin >> a >> b >> c >> d;

    # Calculate the product of the differences between the first two and the last two integers
    # This represents the area of a rectangle defined by the points (a, b) and (c, d)
    cout << (a - c) * (b - d) << endl;

    return 0; # Return 0 to indicate successful completion of the program

