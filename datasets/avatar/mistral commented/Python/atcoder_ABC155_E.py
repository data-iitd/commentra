# Import necessary modules and define input methods
import sys
input_methods = [ 'clipboard' , 'file' , 'key' ]

# Initialize using method and input method
using_method = 0
input_method = input_methods [ using_method ]

# Define helper function to read input as a list of integers
IN = lambda : map ( int , input ( ).split ( ) )

# Define modulus constant
mod = 1000000007

# Define main function 'main_b'
def main_b ( ):
    # Read input string 's'
    s = input ( )

    # Initialize variables 'pp' and 'na'
    pp = 0
    na = 0

    # Iterate through each character in the input string 's'
    for i, c in enumerate ( s [ : : - 1 ] ):
        # Calculate current character value 'cc'
        cc = na + int ( c )
        na = 0

        # Update 'pp' based on the current character value 'cc'
        if cc <= 4:
            pp += cc
        else:
            # If current character is the last character, add 1 to 'pp'
            if i == len ( s ) - 1:
                pp += 1
            # Otherwise, add 10 - 'cc' to 'pp'
            pp += 10 - cc

    # Print the result 'pp'
    print ( pp )

# Define main function 'main'
def main ( ):
    # Read input string 's'
    s = input ( )

    # Initialize variables 'pmin' and 'mmin' with large initial values
    pmin = 1000
    mmin = 0

    # Add a leading zero to the input string 's'
    s = '0' + s

    # Iterate through each character in the input string 's'
    for c in s [ : : - 1 ]:
        # Calculate new minimum values 'npmin' and 'nmmin' based on current character value 'v' and previous minimum values 'pmin' and 'mmin'
        npmin = min ( pmin + 10 - ( int ( c ) + 1 ) , mmin + 10 - int ( c ) )
        nmmin = min ( pmin + int ( c ) + 1 , mmin + int ( c ) )

        # Update 'pmin' and 'mmin' with the new minimum values
        pmin = npmin
        mmin = nmmin

    # Return the minimum value between 'pmin' and 'mmin'
    return min ( pmin , mmin )

# Define a helper function 'pa' to print values during testing
def pa ( v ):
    if isTest:
        print ( v )

# Define function to read input from clipboard
def input_clipboard ( ):
    import clipboard
    input_text = clipboard.get ( )
    input_l = input_text.splitlines ( )
    for l in input_l:
        yield l

# Main program execution starts here
if __name__ == "__main__":
    # Check current platform and set input method accordingly
    if sys.platform == 'ios':
        if input_method == input_methods [ 0 ]:
            ic = input_clipboard ( )
            input = lambda : ic.__next__ ( )
        elif input_method == input_methods [ 1 ]:
            sys.stdin = open ( 'inputFile.txt' )
        else:
            pass
        isTest = True
    else:
        pass

    # Call main function and print result
    ret = main ( )
    if ret is not None:
        print ( ret )
