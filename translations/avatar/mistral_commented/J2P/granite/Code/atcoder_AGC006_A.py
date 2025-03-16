
import sys

# Function declaration and initialization of variables
def getFail ( b, m ) :
    # Main logic of the function
    j = 0
    f = [ 0 ] * ( m + 1 )
    for i in range ( 2, m + 1 ) :
        while j > 0 and b [ j + 1 ]!= b [ i ] :
            j = f [ j ]
        if b [ j + 1 ] == b [ i ] :
            j += 1
        f [ i ] = j
    return f

# Main function declaration and initialization of variables
def main ( ) :
    # Reading the input from the console
    n = int ( input ( ) )
    s1 = input ( )
    str = input ( )

    cnt = 0
    b = [ ]
    # Concatenating the two strings and creating character arrays for each
    for i in range ( n ) :
        b.append ( str [ i ] )
        cnt += 1
    for i in range ( n ) :
        b.append ( s1 [ i ] )
        cnt += 1

    f = getFail ( b, cnt )
    len = min ( f [ cnt ], min ( n, n ) )
    # Writing the output to the console
    print ( 2 * n - len )

if __name__ == "__main__" :
    main ( )

# End of code