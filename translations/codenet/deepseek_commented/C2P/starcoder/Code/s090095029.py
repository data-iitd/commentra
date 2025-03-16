#include <stdio.h>  # Include standard input-output library
#include <stdbool.h>  # Include library for boolean types
#include <string.h>  # Include library for string manipulation

def main():
    n, m = map(int, input().split())  # Read two integers n and m from standard input
    r0 = [False] * n  # Initialize array r0 with false values
    r1 = []  # Initialize array r1
    nr1 = 0  # Initialize array r1 and set nr1 to 0
    for i in range(m):
        a, b = map(int, input().split())  # Read pairs of integers a and b
        if a > b:
            a, b = b, a  # Ensure a is less than or equal to b
        if a == 1:
            r0[b - 1] = True  # If a is 1, set r0[b-1] to true
        if b == n:
            r1.append(a - 1)  # If b is n, add a-1 to r1
    res = False
    for i in range(len(r1)):
        if r0[r1[i]]:
            res = True  # Check if any element in r1 has a true in r0
    if res:
        print("POSSIBLE")  # Print "POSSIBLE" if res is true
    else:
        print("IMPOSSIBLE")  # Print "IMPOSSIBLE"
    return 0

main()

