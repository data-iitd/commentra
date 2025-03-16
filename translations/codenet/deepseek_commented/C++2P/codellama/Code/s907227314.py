#include <iostream> // Include the iostream library for input and output operations
#include <string>   // Include the string library for string operations

using namespace std; // Use the standard namespace to avoid prefixing standard library names with 'std::'

int main() {
    string s; // Declare a string variable to store the input
    cin >> s; // Read input from the user and store it in the string variable 's'
    int a, z; // Declare two integer variables to store the positions of 'A' and 'Z'

    # The first for loop iterates through the string to find the position of the first occurrence of 'A'
    for i in range(len(s)):
        if s[i] == 'A':
            a = i; # Assign the position of 'A' to variable 'a' and break the loop
            break

    # The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
    for i in range(len(s) - 1, -1, -1):
        if s[i] == 'Z':
            z = i; # Assign the position of 'Z' to variable 'z' and break the loop
            break

    # Calculate the length of the substring between the first 'A' and the last 'Z' and print it
    print(z - a + 1)
    return 0 # Return 0 to indicate successful execution
}

