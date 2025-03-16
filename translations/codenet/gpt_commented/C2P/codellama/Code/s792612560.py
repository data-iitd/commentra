#include <stdio.h>

int main(void) {
    # Declare an integer variable 'n' for input and an unsigned long long int 'm' for storing the result
    n = int(input())
    m = n

    # Decrease 'n' by 1 to prepare for the factorial calculation
    n -= 1

    # Loop to calculate the factorial of 'n' (m = n!)
    for i in range(n, 1, -1):
        # Multiply 'm' by the current value of 'n'
        m *= i

    # Print the calculated factorial value stored in 'm'
    print(m)

    # Return 0 to indicate successful completion of the program
    return 0
}

