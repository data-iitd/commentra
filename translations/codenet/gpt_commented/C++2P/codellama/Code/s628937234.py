#include <iostream>  # Include the iostream library for input and output
#include <algorithm> # Include the algorithm library (not used in this code)
#include <string>    # Include the string library for string manipulation

int main():
    using namespace std; # Use the standard namespace to avoid prefixing std::

    s, t = "", "" # Declare two strings: s for input and t for the output format

    cin >> s # Read a string input from the user and store it in s

    # Construct the abbreviated version of the string
    t = s[0] # Start with the first character of the input string
    t += str(len(s) - 2) # Append the number of characters between the first and last characters
    t += s[len(s) - 1] # Append the last character of the input string

    print(t) # Output the abbreviated string

    return 0 # Return 0 to indicate successful completion of the program

