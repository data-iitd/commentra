#include <stdio.h>  # Step 1: Include necessary headers

def main():  # Step 2: Define the main function
    a, b, c = input(), input(), input()  # Step 3: Declare variables

    if b > a * c:  # Step 4: Implement the if-else condition
        print(c)  # If true, print c
    else:
        print(b / a)  # Otherwise, print b divided by a

    return 0  # Step 5: Return 0 to indicate successful execution

# 