
# Go:
package main

import (
        "fmt"
)

// solution calculates the product of (n-2) and (m-2) with adjustments for negative values.
def solution(n, m):
        # Decrease n and m by 2 to adjust for some offset
        n = n - 2
        m = m - 2
        
        # If the adjusted n is negative, set it to 1
        if n < 0:
                n = 1
        
        # If the adjusted m is negative, set it to 1
        if m < 0:
                m = 1
        
        # Return the product of the adjusted n and m
        return n * m

def main():
        # Declare variables to hold input values for n and m
        n, m = 0, 0
        
        # Read input values for n and m from the standard input
        n, m = map(int, input().split())
        
        # Call the solution function and print the result
        print(solution(n, m))

# 