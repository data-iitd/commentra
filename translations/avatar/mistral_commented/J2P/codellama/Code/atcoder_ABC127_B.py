
import sys

# Reading input variables from the user
r = int ( sys.stdin.readline ( ) )
d = int ( sys.stdin.readline ( ) )
x = int ( sys.stdin.readline ( ) )

# Running the loop for 10 iterations
for i in range ( 10 ) :
    # Multiplying 'r' with 'x' and subtracting 'd' from it
    x = r * x - d

    # Writing the result to the output stream
    print ( x )

# Closing the output stream
sys.stdout.close ( )

