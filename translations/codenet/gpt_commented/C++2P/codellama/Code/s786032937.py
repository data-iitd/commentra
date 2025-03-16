#include<iostream>   # Include the iostream library for input and output operations
#include<algorithm>  # Include the algorithm library for various algorithms (not used in this code)
#include<string>     # Include the string library for string manipulations (not used in this code)
#include<vector>     # Include the vector library for using the vector container (not used in this code)
#include<queue>      # Include the queue library for using the queue container (not used in this code)
#include<map>        # Include the map library for using the map container (not used in this code)
using namespace std;

int main()
{
    int n;  # Declare an integer variable 'n' to store the number of sides of the polygon
    cin >> n;  # Read the number of sides from user input

    # Calculate the sum of the interior angles of a polygon with 'n' sides
    # The formula for the sum of interior angles is (n - 2) * 180
    print((n - 2) * 180)  # Output the calculated sum of interior angles

    return 0;  # Return 0 to indicate successful completion of the program
}

