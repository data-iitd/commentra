
import sys

def power ( a ) :
    # Function definition for calculating the power of a number
    res = 0
    while ( a > 0 ) :
        res += 1
        a = a // 10
    return res

def mult ( a ) :
    # Function definition for calculating the product of a number with the maximum number that can be formed using its digits
    pow = power(a)
    max = 0
    for j in range ( 0, pow ) :
        # Loop to calculate the maximum number that can be formed using the digits of the number 'a'
        max = max * 10 + 9
    return a * ( max - a )

def main ( ) :
    # Main function definition

    l = int ( input ( ) ) # Reading the first number 'l' from the console
    r = int ( input ( ) ) # Reading the second number 'r' from the console

    res = 0 # Initializing the result variable to 0

    maxxes = [ 0 ] * 10 # Creating an array'maxxes' of size 10 to store the maximum numbers that can be formed using each digit

    temp = 0 # Initializing a temporary variable to 0

    for i in range ( 0, 10 ) :
        # Loop to calculate and store the maximum numbers that can be formed using each digit
        temp = temp * 10 + 9
        maxxes [ i ] = temp // 2 * ( temp - temp // 2 )

    res = max ( mult(l), res ) # Calculate the product of the first number 'l' with the maximum number that can be formed using its digits and update the result variable
    res = max ( mult(r), res ) # Calculate the product of the second number 'r' with the maximum number that can be formed using its digits and update the result variable

    temp = 0 # Resetting the temporary variable to 0

    for i in range ( 0, 10 ) :
        # Loop to check if the range between the first and second number includes the maximum number that can be formed using the 'i'th digit
        temp = temp * 10 + 9
        if ( l <= temp // 2 and temp // 2 <= r ) :
            # Check if the range includes the maximum number that can be formed using the 'i'th digit
            res = max ( maxxes [ i ], res ) # Update the result variable with the maximum number that can be formed using the 'i'th digit if the condition is true

    print ( res ) # Printing the final result

if __name__ == "__main__" :
    main ( ) # Call the main function

