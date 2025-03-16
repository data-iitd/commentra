
# Importing the utility package for collections and I/O operations
import java.util.* ;
import java.io.* ;

# Main method is the entry point of the program
def main ( ):
    sc = java.util.Scanner ( System.in ) ;  # Creating a Scanner object to read input from the console
    n = sc.nextInt ( ) ;                # Reading the number of elements in the array from the input
    arr = [ ] ;             # Creating an integer array of size n
    arr.append ( sc.nextInt ( ) ) ;             # Reading the first element of the array from the input

    # Initializing a for loop to read and store the remaining elements of the array
    for i in range ( 1, n ):
        x = sc.nextInt ( ) ;            # Reading an element from the input
        arr.append ( x + arr [ i - 1 ] ) ;       # Assigning the current element the sum of the previous element and the current input

    m = sc.nextInt ( ) ;                # Reading the number of queries from the input
    q = [ ] ;              # Creating an integer array of size m to store the queries

    # Initializing a for loop to read and store the queries in the array q
    for i in range ( 0, m ):
        q.append ( sc.nextInt ( ) ) ;          # Reading a query from the input

    # Initializing a for loop to process each query and print the result
    for k in range ( 0, m ):
        print ( fun ( arr, q [ k ], n, m ) + 1 ) ; # Calling the fun function with the array, query, size of the array, and number of queries as arguments and printing the result with an offset of 1

# fun function takes an array, a query, the size of the array, and the number of queries as arguments
def fun ( arr, q, n, m ):
    res = 0 ;                          # Initializing a variable to store the result
    i = 0 ; j = n ;                     # Initializing two variables to represent the left and right indices of the array

    # Using a while loop to perform a binary search on the array
    while ( i <= j ):
        md = i + ( j - i ) / 2 ;        # Calculating the middle index of the subarray
        if ( arr [ md ] == q ):             # If the middle element is equal to the query, return the middle index
            return md ;
        elif ( arr [ md ] > q ):       # If the middle element is greater than the query, update the result and shift the right index towards the left
            res = md ;
            j = md - 1 ;
        else:                           # If the middle element is less than the query, shift the left index towards the right
            i = md + 1 ;

    # If the query is not present in the array, return the index where it should be inserted
    return res ;

# Calling the main method
if __name__ == "__main__":
    main ( )

