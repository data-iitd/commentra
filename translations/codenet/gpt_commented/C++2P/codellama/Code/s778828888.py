#include <cstdio>
#include <algorithm>

def main():
    # Declare variables for the number of elements (n), number of inputs (m), and the starting point (x)
    n, m, x = 0, 0, 0
    # Initialize an array to keep track of the presence of numbers (size 105 to accommodate possible values)
    a = [0] * 105
    
    # Read the values of n, m, and x from standard input
    n, m, x = map(int, input().split())

    # Read m numbers from input and mark their presence in the array 'a'
    for i in range(m):
        temp = int(input())
        a[temp] = 1

    # Initialize counters for the number of present elements to the right (ansr) and left (ansl) of x
    ansl, ansr = 0, 0

    # Count how many numbers are present from x to n (right side)
    for i in range(x, n+1):
        ansr += a[i] # Increment ansr if a[i] is 1 (indicating presence)

    # Count how many numbers are present from x to 0 (left side)
    for i in range(x, -1, -1):
        ansl += a[i] # Increment ansl if a[i] is 1 (indicating presence)

    # Output the minimum of the counts from both sides
    print(min(ansl, ansr))
    
    # Return 0 to indicate successful completion of the program
    return 0

