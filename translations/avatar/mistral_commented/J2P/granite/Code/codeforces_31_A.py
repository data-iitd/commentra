

# Python program to find three elements in an array whose sum is equal to the current element

# Importing the utility class Scanner from java.util package
import java.util.* ;

# Main method is the entry point of the Java application
def main ( ) :
    sc = Scanner ( ) ; # Creating an instance of Scanner class to read input from the standard input stream
    n = sc.nextInt ( ) ; # Reading the number of elements in the array from the standard input stream

    f = 0 ; # Initializing a flag variable to keep track of whether an element is found in the array
    a = [ ] ; # Creating an integer array of size n

    # Reading the elements of the array from the standard input stream
    for i in range ( n ) :
        a.append ( sc.nextInt ( ) ) ;

    k = 0 ; # Initializing an index variable
    for k in range ( n ) :
        t = a [ k ] ; # Storing the current element in a temporary variable
        i = 0 ; # Initializing an index variable
        for i in range ( n ) :
            # Skipping the comparison if the current index is same as the index of the current element
            if ( i!= k ) :
                j = 0 ; # Initializing an index variable
                for j in range ( n - 1 ) : # Inner most loop to compare the current element with all the previous elements in the array
                    if ( i!= j and t == ( a [ i ] + a [ j ] ) ) : # Checking if the sum of the current and previous elements is equal to the current element
                        f = 1 ; # Setting the flag variable to 1 if a match is found
                        break ; # Exiting the inner most loop if a match is found
                if ( f == 1 ) : # Checking if the flag variable is set to 1, indicating a match is found
                    break ; # Exiting the inner loop if a match is found
        if ( f == 1 ) : # Checking if the flag variable is set to 1, indicating a match is found
            print ( k + 1, end = " " ) ; # Printing the index of the current element
            print ( j + 1, end = " " ) ; # Printing the index of the previous element
            print ( i + 1 ) ; # Printing the index of the current element
            f = 0 ; # Resetting the flag variable to 0 for the next iteration
        else :
            print ( - 1 ) ; # Printing "-1" if no match is found

# End of the Python program
