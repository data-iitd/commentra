
I = input
n , m = map ( int , I ( ).split ( ) )
# Read the values of n and m from standard input

b = [ 1 ] * n * 2
# Initialize a list `b` with 1s, size is 2*n

b [ 0 ] = b [ n - 1 ] = b [ n ] = b [ 2 * n - 1 ] = 0
# Set specific positions in `b` to 0

for i in range ( m ) :
    r , c = map ( int , I ( ).split ( ) )
    # Read each pair of row and column indices
    b [ r - 1 ] = b [ n + c - 1 ] = 0
    # Update `b` based on the input pairs

if n % 2 and b [ n // 2 ] and b [ n + n // 2 ] : b [ n // 2 ] = 0
# Check if `n` is odd and specific positions in `b` are 1, then set them to 0

print ( sum ( b ) )
# Print the sum of the list `b`

