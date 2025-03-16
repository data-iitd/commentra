import sys
def main ( ) :
    # Read the values of S and W from a single line of input
    S , W = map ( int , input ( ).split ( ) )
    # Check if the value of W is greater than or equal to S
    # If true, print "unsafe"
    print ( "unsafe" ) if ( S <= W ) else print ( "safe" )
    # Ensure the main function is called only when the script is executed directly
if __name__ == '__main__' :
    main ( )