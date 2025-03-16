#include <stdio.h>  # Include the standard input-output library

int main():
    n, m = input("Enter two integers: ").split()  # Read two integers from the standard input and store them in n and m
    print((int(n) - 1) * (int(m) - 1))  # Print the result of the expression (n - 1) * (m - 1)
    fflush(stdout)  # Ensure buffered output is written to the standard output stream immediately
    return 0  # Return 0 to indicate successful execution

