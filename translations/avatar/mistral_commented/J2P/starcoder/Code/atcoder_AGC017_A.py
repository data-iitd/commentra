
# Importing necessary utility classes
import math
import sys

# Function to calculate the binomial coefficient C(n, m) using BigInteger
def C ( n, m ) :
    res = 1  # Initialize result as 1

    # Calculate the binomial coefficient for n choose m
    for i in range ( m - n + 1, m + 1 ) :
        res = res * i  # Multiply with current term

    for i in range ( 1, n + 1 ) :
        res = res / i  # Divide with denominator

    return res  # Return the calculated binomial coefficient

if __name__ == "__main__" :
    # Initialize scanner to read input
    sc = sys.stdin

    n, p = map ( int, sc.readline ( ).split ( ) )  # Read the value of n and p from standard input

    k0 = 0 ; k1 = 0  # Initialize counters k0 and k1 to 0

    # Read the values of n elements and count the number of odd and even elements
    for i in range ( n ) :
        x = int ( sc.readline ( ) )

        if ( x % 2 == 1 ) :
            k1 += 1  # Increment the counter k1 if the current element is odd
        else :
            k0 += 1  # Increment the counter k0 if the current element is even

    ans = 1  # Initialize answer as 1

    # Calculate the answer based on the given conditions
    for i in range ( k0 ) :
        ans = ans * 2  # Multiply answer with 2 raised to the power of counter i

    if ( p == 0 ) :  # If p is 0, calculate the answer using the given formula
        add = 0

        for i in range ( 0, k1 + 1, 2 ) :
            add += C ( i, k1 )  # Calculate the sum of C(i, k1) for i from 0 to k1 with a step of 2

        ans = ans * add  # Multiply the answer with the calculated sum

        print ( ans )  # Print the final answer
    else :  # If p is not 0, calculate the answer using a similar formula
        add = 0

        for i in range ( 1, k1 + 1, 2 ) :
            add += C ( i, k1 )  # Calculate the sum of C(i, k1) for i from 1 to k1 with a step of 2

        ans = ans * add  # Multiply the answer with the calculated sum

        print ( ans )  # Print the final answer

