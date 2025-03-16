#include <stdio.h>

# The main function is the entry point of the program
int main():
    # Declare variables n, k, and cnt of type int
    n, k, cnt = 0, 0, 0

    # Read two integers n and k from the standard input using scanf()
    scanf("%d%d", &n, &k)
    # Initialize variable cnt to zero
    cnt = 0
    # Loop through n times using a while loop
    while n > 0:
        # Declare variable h of type int
        h = 0

        # Read an integer h from the standard input using scanf()
        scanf("%d", &h)
        # If h is greater than or equal to k, increment cnt by 1
        if h >= k:
            cnt += 1
        # Decrement n by 1
        n -= 1
    # Print the value of cnt to the standard output using printf()
    printf("%d\n", cnt)
    # Return 0 to indicate successful execution of the program
    return 0

