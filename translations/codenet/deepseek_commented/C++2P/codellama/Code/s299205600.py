#include <iostream>  # Include the Input/Output stream library
#include <string>    # Include the string library
using namespace std; # Use the standard namespace

int main():
    int a;           # Declare an integer variable 'a'
    int b;           # Declare an integer variable 'b'
    cin >> a;        # Read the value of 'a' from standard input
    cin >> b;        # Read the value of 'b' from standard input
    int result;      # Declare an integer variable 'result' to store the final result

    # Determine the value of 'result' based on the values of 'a' and 'b'
    if a > b:
        result = 2 * a - 1 # If 'a' is greater than 'b', calculate 'result' as 2 * 'a' - 1
    elif a == b:
        result = 2 * a     # If 'a' is equal to 'b', calculate 'result' as 2 * 'a'
    else:
        result = 2 * b - 1 # If 'a' is less than 'b', calculate 'result' as 2 * 'b' - 1

    cout << result << endl # Output the value of 'result' to standard output

    return 0 # Return 0 to indicate successful execution

