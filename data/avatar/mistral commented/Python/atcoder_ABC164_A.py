# Import the sys module for handling system-specific exceptions
import sys

# Define the main function that takes no arguments and returns nothing
def main( ) :

    # Get the input as a list of two integers, S and W, using the map function
    S, W = map( int, input().split() )

    # Check if the condition S <= W is true or false and print the corresponding message
    if S <= W:
        print( "unsafe" )
    else:
        print( "safe" )

# Run the main function if the script is executed directly
if __name__ == '__main__' :
    main( )
