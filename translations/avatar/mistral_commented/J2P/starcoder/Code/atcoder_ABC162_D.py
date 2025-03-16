
import sys ; // Importing the utility module

def main ( ):
    n = int ( sys.stdin.readline ( ) ) ; // Reading the first integer input from the console
    s = sys.stdin.readline ( ).strip ( ) ; // Reading the second string input from the console
    rc = 0 ; // Initializing the count for 'R' characters to zero
    gc = 0 ; // Initializing the count for 'G' characters to zero
    bc = 0 ; // Initializing the count for other characters to zero

    for i in range ( len ( s ) ) : # Starting a loop to iterate through each character in the string
        if ( s [ i ] == 'R' ) : # Checking if the current character is 'R'
            rc += 1 ; # Incrementing the count for 'R' characters
        elif ( s [ i ] == 'G' ) : # Checking if the current character is 'G'
            gc += 1 ; # Incrementing the count for 'G' characters
        else : # If the current character is not 'R' or 'G'
            bc += 1 ; # Incrementing the count for other characters

    result = rc * gc * bc ; # Multiplying the counts of 'R', 'G' and other characters to get the initial result

    for i in range ( 1, n + 1 ) : # Starting a loop to iterate through each pair of indices in the string
        for k in range ( i + 1, n + 1 ) : # Starting a nested loop to iterate through each pair of indices that are not too far apart
            if ( ( i + k ) % 2 == 0 ) : # Checking if the sum of the indices is even
                is = s [ i - 1 ] ; # Storing the character at the index i-1
                ks = s [ k - 1 ] ; # Storing the character at the index k-1
                js = s [ ( ( i + k ) // 2 ) - 1 ] ; # Storing the character at the midpoint between i and k
                if ( is!= ks and ks!= js and js!= is ) : # Checking if the characters at the three indices are different
                    result -= 1 ; # Decrementing the result if they are

    print ( result ) ; # Printing the final result to the console

if __name__ == '__main__' :
    main ( ) ; // Starting the main method

