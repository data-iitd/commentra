
# Importing the Scanner class for user input
import java.util.Scanner ;

# Main method to start the program
def main ( ):
    s = java.util.Scanner ( ) ;  # Creating a new Scanner object to read user input

    x = s.nextInt ( ) ;  # Reading the first integer value from user input
    y = s.nextInt ( ) ;  # Reading the second integer value from user input
    a = s.nextInt ( ) ;  # Reading the third integer value from user input
    b = s.nextInt ( ) ;  # Reading the fourth integer value from user input

    j = 2 ;  # Initializing variables
    i, x1 = 0, y1 = 0 ;  # Initializing variables
    c = 0 ;  # Initializing variables
    ans = True ;  # Initializing a boolean variable to keep track of the result

    c = max ( x, y ) ;  # Finding the maximum value between x and y

    if ( c > b ) :  # Checking if the maximum value is greater than b
        print ( "0" ) ;  # If true, printing 0 and setting ans to false
        ans = False ;

    while ( c % min ( x, y )!= 0 and ans ) :  # Loop to find the greatest common divisor (GCD)
        if ( x > y ) :  # If x is greater than y
            c = x * j ;  # Multiplying x by j and updating c
            j += 1 ;  # Incrementing j
        else :
            c = y * j ;  # Multiplying y by j and updating c
            j += 1 ;  # Incrementing j

        if ( c > b ) :  # Checking if the current value of c is greater than b
            print ( "0" ) ;  # If true, printing 0 and setting ans to false
            ans = False ;
            break ;  # Exiting the loop

    if ( ans ) :  # If the GCD has been found
        count = 0 ;  # Initializing a counter variable
        i = a ;  # Starting the loop from a

        for i in range ( a, b + 1 ) :  # Loop to find the number of times c divides i
            if ( i % c == 0 ) : break ;  # If i is divisible by c, breaking the loop

        if ( i!= b + 1 ) :  # Checking if the last number in the range is divisible by c
            print ( ( ( b - i ) / c ) + 1 ) ;  # Printing the result
        else :
            print ( "0" ) ;  # If the last number is not divisible by c, printing 0

# Calling the main method
if __name__ == "__main__" :
    main ( )

# 