
import sys ; # Importing sys module

def main ( ) :
    n = int ( input ( ) ) ; # Reading an integer input
    s = "" ; # Initializing an empty string to store binary representation
    
    # Converting the integer to binary representation
    while ( n > 0 ) :
        x = n % 2 ; # Getting the remainder when divided by 2
        n //= 2 ; # Dividing the number by 2
        s += str ( x ) ; # Appending the remainder to the string
    
    ans = 0 ; # Initializing a variable to count the number of '1's
    
    # Counting the number of '1's in the binary representation
    for i in range ( len ( s ) ) :
        if ( s [ i ] == '1' ) :
            ans += 1 ; # Incrementing the count if the character is '1'
    
    print ( ans ) ; # Printing the count of '1's

if __name__ == "__main__" :
    main ( ) ; # Calling the main function

