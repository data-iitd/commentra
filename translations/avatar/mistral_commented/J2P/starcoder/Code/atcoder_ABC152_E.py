import java.math.*;   // Importing BigInteger class for large integer arithmetic
import java.util.*;   // Importing Scanner class for reading input
import java.util.function.*; // Importing functional interfaces for lambda expressions

def main():
    # Main method is the entry point of the Java application
    sc = Scanner( System.in )  # Creating a new Scanner object to read input from the standard input stream
    N = sc.nextInt()           # Reading the number of integers N from the standard input
    A = [0] * N               # Creating an integer array A of size N

    # Using a for loop to read each integer in the array A from the standard input
    for i in range(N):
        A[i] = sc.nextInt()

    # Closing the Scanner object to prevent resource leaks
    sc.close()

    lcm = BigInteger.ONE       # Initializing lcm as 1

    # Using a for loop to calculate the least common multiple (lcm) of all integers in array A
    for ai in A:
        a = BigInteger.valueOf( ai )  # Converting integer ai to BigInteger a
        lcm = lcm.divide( lcm.gcd( a ) ).multiply( a ) # Calculating lcm using division and multiplication

    mod = 1000000007           # Setting the modulus value
    modLcm = lcm.remainder( BigInteger.valueOf( mod ) ).longValue() # Calculating the remainder of lcm modulo mod

    ans = 0                    # Initializing answer variable as 0

    # Using a for loop to calculate the answer using modular arithmetic
    for ai in A:
        ans = ( ans + modDiv( modLcm, ai, mod ) ) % mod

    # Printing the answer to the standard output stream
    print( ans )

def modDiv( a, b, mod ):
    return ( a % mod ) * modInv( b, mod ) % mod

def modInv( x, mod ):
    return modPow( x, mod - 2, mod )

def modPow( b, e, mod ):
    ans = 1
    x = b % mod
    for y in range( e, 0, -1 ):
        if ( ( y & 1 ) == 1 ):
            ans = ( ans * x ) % mod
        x = ( x * x ) % mod
    return ans

if __name__ == "__main__":
    main()

