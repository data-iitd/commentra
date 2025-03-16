#include <iostream>  # Include the iostream library for input and output operations.
#include <cstdio>    # Include the cstdio library for standard input/output functions.
#include <cstdlib>   # Include the cstdlib library for general utilities like dynamic memory allocation, conversion functions, etc.
#include <string>    # Include the string library for string operations.
#include <vector>    # Include the vector library for dynamic array operations.
#include <algorithm> # Include the algorithm library for various algorithms like sort.
#include <numeric>   # Include the numeric library for numeric operations.
#include <map>       # Include the map library for key-value pair based data structure.
#include <stack>     # Include the stack library for stack data structure.
#include <queue>     # Include the queue library for queue data structure.
#include <iomanip>   # Include the iomanip library for manipulators like setprecision.
using namespace std; # Use the standard namespace to avoid prefixing standard library components with 'std::'.
using ll = long long; # Define 'll' as an alias for 'long long' to make the code more readable.
using P = pair<int, int>; # Define 'P' as an alias for 'pair<int, int>' to make the code more readable.

def main(): # Define the main function which is the entry point of the program.
    r, g, b, n = map(int, input().split()) # Read four integers from the standard input.
    ans = 0 # Initialize a variable 'ans' to 0 to store the count of valid combinations.

    # Start a nested loop to iterate through possible values of 'i' and 'j' that represent the number of times 'r' and 'g' are used, respectively.
    for i in range(0, n // r + 1):
        for j in range(0, n // g + 1):
            num = n - r * i - g * j # Calculate the remaining value after using 'r * i' and 'g * j'.
            if num >= 0 and num % b == 0: # Check if 'num' is non-negative and divisible by 'b'.
                ans += 1 # Increment 'ans' if the conditions are met.

    print(ans) # Print the value of 'ans' which represents the count of valid combinations.
    return 0 # Return 0 to indicate successful execution of the program.


