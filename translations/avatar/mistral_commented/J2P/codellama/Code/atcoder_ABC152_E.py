import math
import sys

# Main method is the entry point of the Python application
def main ( ):
    # Reading the number of integers N from the standard input
    N = int ( input ( ) )

    # Creating an integer array A of size N
    A = [ 0 ] * N

    # Using a for loop to read each integer in the array A from the standard input
    for i in range ( N ):
        A [ i ] = int ( input ( ) )

    # Initializing lcm as 1
    lcm = 1

    # Using a for loop to calculate the least common multiple (lcm) of all integers in array A
    for ai in A:
        # Converting integer ai to BigInteger a
        a = int ( ai )
        # Calculating lcm using division and multiplication
        lcm = lcm // math.gcd ( lcm , a ) * a

    # Setting the modulus value
    mod = 1000000007
    # Calculating the remainder of lcm modulo mod
    modLcm = lcm % mod

    # Initializing answer variable as 0
    ans = 0

    # Using a for loop to calculate the answer using modular arithmetic
    for ai in A:
        # Calculating the answer using modular division
        ans = ( ans + modDiv ( modLcm , ai , mod ) ) % mod

    # Printing the answer to the standard output stream
    print ( ans )

# A private method modDiv is used to perform modular division
def modDiv ( a , b , mod ):
    # Calculating the modular inverse of b
    bInv = modPow ( b , mod - 2 , mod )
    # Calculating the modular division of a and b
    return ( a % mod ) * bInv % mod

# A private method modPow is used to calculate the power of a number using modular arithmetic
def modPow ( b , e , mod ):
    # Initializing answer variable as 1
    ans = 1
    # Converting the base b to a modular number
    x = b % mod
    # Using a for loop to calculate the power of x using modular arithmetic
    for y in range ( e ):
        # Calculating the modular multiplication of x and ans
        ans = ( ans * x ) % mod
        # Calculating the modular multiplication of x and x
        x = ( x * x ) % mod
    # Returning the answer
    return ans

# A private method modInv is used to calculate the modular inverse of a number
def modInv ( x , mod ):
    # Calculating the modular inverse of x
    return modPow ( x , mod - 2 , mod )

# Calling the main method
main ( )

# End of code
