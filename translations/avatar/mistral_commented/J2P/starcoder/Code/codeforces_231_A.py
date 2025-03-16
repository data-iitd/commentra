import sys ; // Import the sys module for reading input

def main ( ):
    t = int ( sys.stdin.readline ( ) ) ; // Read the number of test cases from the standard input

    # Initialize a counter variable to keep track of the number of valid cases
    count = 0 ;

    # Read the number of test cases and process each one in the while loop
    while ( t > 0 ) :
        a, b, c = map ( int, sys.stdin.readline ( ).split ( ) ) ; // Read the first integer from the standard input
        # Read the second integer from the standard input
        # Read the third integer from the standard input

        # Check if any of the given integers are equal to 1. If so, increment the counter.
        if ( ( a == 1 and b == 1 ) or ( a == 1 and c == 1 ) or ( b == 1 and c == 1 ) or ( a == 1 and b == 1 and c == 1 ) ) :
            count += 1 ; # Increment the counter if any of the given integers are equal to 1

        t -= 1 ; # Decrement the number of test cases

    # Print the value of the counter to the standard output
    print ( count ) ;

if __name__ == '__main__' :
    main ( ) ;

