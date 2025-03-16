
import sys

# Function to find the greatest common divisor of two numbers
def getGCD ( a, b ):
    if ( b == 0 ): # Base case: if b is 0, return a as the gcd
        return a
    else:
        return getGCD ( b, a % b ) # Recursive call: finding the gcd of b and the remainder of a divided by b

# Main method
if __name__ == '__main__':
    n = int ( sys.stdin.readline ( ).strip ( ) ) # Reading the first integer n from the standard input
    m = int ( sys.stdin.readline ( ).strip ( ) ) # Reading the second integer m from the standard input
    a = [ int ( x ) / 2 for x in sys.stdin.readline ( ).strip ( ).split ( " " ) ] # Creating an integer array a of size n

    # Initializing the array a with input values
    gcd = 1 # Declaring a variable gcd to store the greatest common divisor
    lcd = 1 # Declaring and initializing a variable lcm to store the least common multiple

    # Finding the least common multiple of all array elements
    for i in range ( 0, n ):
        gcd = getGCD ( lcd, a [ i ] ) # Finding the greatest common divisor of lcm and the current array element
        lcd = lcd * a [ i ] / gcd # Updating the value of lcm

        # Checking if lcm is greater than m
        if ( lcd > m ):
            print ( 0 ) # If true, printing 0 and returning from the method
            return

    # Checking if any array element is a factor of lcm
    for i in range ( 0, n ):
        if ( ( lcd / a [ i ] ) % 2 == 0 ): # Checking if the remainder of lcm divided by the current array element is 0 and even
            print ( 0 ) # If true, printing 0 and returning from the method
            return

    # Printing the result
    print ( ( m / lcd + 1 ) / 2 )

