
#include<bits/stdc++.h> // This line is an include guard for standard C++ libraries
#include<iostream>      // Input/Output stream library
#include<algorithm>     // Standard template library for algorithms
#include<cmath>         // Mathematical functions library
#include<vector>         // Vector container library
#include<queue>          // Queue container adapter library
#include<set>            // Set container adapter library

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/
// Uncomment this block if you want to use Boost Multiprecision Library for large numbers

from sys import stdin,stdout # Importing the standard input/output library

# Define int as long long for larger input handling
# Define MOD for modular arithmetic
MOD = 1000000007

# The main function begins here
if __name__ == "__main__":

    # Initialize an empty vector 'v' of strings
    v = []

    # Read the number of strings 'N' and their lengths 'L' from the standard input
    N,L = map(int,stdin.readline().split())

    # Allocate memory for 'N' strings in the vector 'v'
    for i in range(N):
        # Read a string's' from the standard input and push it back into the vector 'v'
        s = stdin.readline().strip()
        v.append(s)

    # Sort the strings in the vector 'v' in ascending order using the'sort' function
    v.sort()

    # Iterate through the sorted strings in the vector 'v' and print each string to the standard output
    for i in range(len(v)):
        # Print the current string from the vector 'v' to the standard output
        stdout.write(v[i])

    # Print a newline character at the end of the output
    stdout.write("\n")

