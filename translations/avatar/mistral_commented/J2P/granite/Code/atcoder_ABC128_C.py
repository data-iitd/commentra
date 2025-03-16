

import sys

def main ( ) :
    sc = Scanner ( ) ; # Creating a Scanner object to read input

    N = sc.nextInt ( ) ; # Reading the first integer from the input
    M = sc.nextInt ( ) ; # Reading the second integer from the input

    a = [ 0 ] * N ; # Creating a list of size N to store integers

    # Reading the queries and updating the list accordingly
    for i in range ( M ) :
        k = sc.nextInt ( ) ; # Reading the number of elements to be updated

        for j in range ( k ) : # Iterating through the elements to be updated
            s = sc.nextInt ( ) - 1 ; # Reading the index of the element to be updated

            # Updating the value of the element at the given index
            a [ s ] |= ( 1 << i )

    p = 0 ; # Initializing a variable to store the XOR of all given integers

    # Reading the integers and computing their XOR
    for i in range ( M ) :
        x = sc.nextInt ( ) ; # Reading an integer from the input
        p |= ( x << i ) ; # Computing the XOR of the current integer with the previous result

    ans = 0 ; # Initializing a variable to store the count of valid answers

    # Iterating through all possible combinations of the list elements
    for s in range ( 1 << N ) : # 1 << N represents 2^N
        t = 0 ; # Initializing a variable to store the XOR of the current combination with the list elements

        # Computing the XOR of the current combination with the list elements
        for i in range ( N ) :
            if ( ( s >> i ) & 1 ) == 1 : # Checking if the i-th bit of the current combination is set
                t ^= a [ i ] ; # Updating the XOR of the current combination

        # Checking if the XOR of the current combination and the list elements is equal to the given integers
        if ( p == t ) :
            ans += 1 ; # Incrementing the count of valid answers

    print ( ans ) ; # Printing the count of valid answers
    sc.close ( ) ; # Closing the Scanner object

if __name__ == "__main__" :
    main ( ) ;

