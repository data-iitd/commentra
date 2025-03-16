

import sys  # Importing necessary Python built-in modules

def main ( ) :
    scan = sys.stdin  # Creating a file object'scan' to read input from the standard input stream
    n = int ( scan.readline ( ) )  # Reading the first integer from the standard input stream and assigning it to the variable 'n'
    i = 1  # Initializing the variable 'i' to 1
    k = 0  # Initializing the variable 'k' to 0
    p = 1  # Initializing the variable 'p' to 1
    flag = True  # Initializing the boolean variable 'flag' to true
    a = [ 0 ] * 1000  # Declaring and initializing a list 'a' of size 1000 with all elements set to 0

    while ( k <= n ) :  # Starting a while loop that runs as long as 'k' is less than or equal to 'n'
        i += k  # Incrementing the variable 'i' by the value of 'k'
        if ( i >= n ) :  # Checking if the value of 'i' is greater than or equal to 'n'
            i = i - n  # If yes, then decrement 'i' by 'n' until it becomes less than 'n'
        a [ i ] += 1  # Incrementing the value of the 'i'-th element of the list 'a' by 1
        k += 1  # Incrementing the variable 'k' by 1

    for i in range ( n ) :  # Starting a for loop that runs from 0 to 'n'-1
        if ( a [ i ] == 0 ) :  # Checking if the 'i'-th element of the list 'a' is equal to 0
            flag = False  # If yes, then set the boolean variable 'flag' to false
            break  # Exiting the for loop

    if ( flag ) :  # Checking if the boolean variable 'flag' is still true after the for loop
        print ( "YES" )  # If yes, then print "YES" to the standard output stream
    else :  # Otherwise
        print ( "NO" )  # Print "NO" to the standard output stream

    scan.close ( )  # Closing the file object'scan' to free up system resources

if __name__ == "__main__" :  # Executing the main function only if the script is run directly
    main ( )  # Calling the main function

