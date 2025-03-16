# Read N and X from input
N , X = [ int ( _ ) for _ in input ( ).split ( ) ]

# Import the permutations function from itertools
from itertools import permutations

# Define the calc function which processes a list x
def calc ( x ) :
    # Define a nested sub function within calc for further processing
    def sub ( y , debug = 0 ) :
        # Print the current state of y if debug mode is on
        if debug :
            print ( "D" , y )
        # Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while len ( y ) > 1 :
            y = [ sorted ( y [ i : i + 3 ] ) [ 1 ] for i in range ( len ( y ) - 2 ) ]
            # Print the current state of y if debug mode is on
            if debug :
                print ( "D" , y )
        # Return the final single element of y
        return y
    # Process the input list x using sub function
    y = sub ( x )
    # Check if the final element of y is 2
    if y [ 0 ] == 2 :
        # Call sub again with debug mode on and print the result
        sub ( x , 1 )
        print ( "=" , x )
    # Return the first element of the final y
    return y [ 0 ]

# Check if X is 1 or N * 2 - 1, print "No" if true
if X == 1 or X == N * 2 - 1 :
    print ( "No" )
else :
    # Print "Yes" if X is not 1 or N * 2 - 1
    print ( "Yes" )
    # Construct the list xs based on the value of X
    if X == N * 2 - 2 :
        xs = list ( range ( N - 1 , X + 2 ) ) + list ( range ( 1 , N - 1 ) )
    else :
        ys = list ( range ( 1 , X - 1 ) ) + list ( range ( X + 3 , N * 2 ) )
        xs = ys [ : N - 3 ] + [ X + 2 , X - 1 , X , X + 1 ] + ys [ N - 3 : ]
    # Print each element of xs
    for x in xs :
        print ( x )
