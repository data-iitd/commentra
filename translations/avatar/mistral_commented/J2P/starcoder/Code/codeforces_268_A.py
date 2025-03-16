
# Importing the utility class Scanner from the Python standard library
import java.util.* ;

def main ( ):
    sc = Scanner ( ) ; # Creating a new Scanner object to read input from the standard input stream

    n = Integer.parseInt ( sc.nextLine ( ) ) ; # Reading the first line of the input containing the number of integers n

    result = 0 ; # Initializing the variable result to zero

    h = [ ] ; # Creating an integer array h of size n
    g = [ ] ; # Creating an integer array g of size n

    for i in range ( n ) : # Iterating through each index i from 0 to n-1 in the first for loop
        h [ i ] = sc.nextInt ( ) ; # Reading an integer value from the standard input stream and assigning it to the current index of array h
        g [ i ] = sc.nextInt ( ) ; # Reading an integer value from the standard input stream and assigning it to the current index of array g

    for i in range ( n ) : # Iterating through each index i from 0 to n-1 in the second for loop
        for j in range ( n ) : # Nested for loop iterating through each index j from 0 to n-1
            if ( h [ i ] == g [ j ] ) : # Checking if the current element of array h is equal to the current element of array g
                result ++ ; # Incrementing the result variable if the condition is true

    print ( result ) ; # Printing the final result to the standard output stream

if __name__ == '__main__' :
    main ( ) ;

