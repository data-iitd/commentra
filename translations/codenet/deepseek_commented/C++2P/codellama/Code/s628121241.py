#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

// Function to calculate the greatest common divisor (GCD) using recursion
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

# Take an integer input from the user
R = int(input())

# Check the value of R and print the corresponding output
if R < 1200:
    print("ABC")
elif R >= 2800:
    print("AGC")
else:
    print("ARC")

