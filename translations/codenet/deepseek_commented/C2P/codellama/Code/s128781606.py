#include <stdio.h>  # Step 1: Include the standard input/output library.

def main():  # Step 2: Define the main function.
    A, B, C, D, E, max = 0, 0, 0, 0, 0, 0  # Step 3: Declare integer variables A, B, C, D, E, and max.

    A, B = input().split()  # Step 4: Read two integers A and B from the user.

    C = int(A) + int(B)  # Step 5: Calculate the sum of A and B, store it in C.
    D = int(A) - int(B)  # Step 6: Calculate the difference between A and B, store it in D.
    E = int(A) * int(B)  # Step 7: Calculate the product of A and B, store it in E.

    max = C  # Step 8: Initialize max with the value of C.

    if max < D:  # Step 9: Compare max with D and update max if D is greater.
        max = D

    if max < E:  # Step 10: Compare max with E and update max if E is greater.
        max = E

    print(max)  # Step 11: Print the maximum value.
    return 0  # Step 12: Return 0 to indicate successful execution.


