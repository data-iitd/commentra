#include <stdio.h>  # Include the standard input/output library

def main():
    n, k = map(int, input().split())  # Read input values for n and k
    l = 0  # Declare integer variables for counting
    r = 0

    if k % 2 == 0:  # Check if k is even
        for i in range(1, n + 1):  # Iterate from 1 to n
            if i % k == k // 2:  # Check if i modulo k equals k/2
                l += 1  # Increment l if condition is true
            elif i % k == 0:  # Check if i modulo k equals 0
                r += 1  # Increment r if condition is true
        print(l * l * l + r * r * r)  # Print the result of l^3 + r^3
    else:  # If k is odd
        for i in range(1, n + 1):  # Iterate from 1 to n
            if i % k == 0:  # Check if i modulo k equals 0
                r += 1  # Increment r if condition is true
        print(r * r * r)  # Print the result of r^3

if __name__ == "__main__":
    main()  # Call the main function

