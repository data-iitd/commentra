A , B , C , D = map ( int , input ( ).split ( ) )
m = 998244353

# Initialize a 2D list d with dimensions (C+1) x (D+1), filled with zeros
d = [ [ 0 ] * ( D + 1 ) for _ in range ( C + 1 ) ]

# Set the starting point for our calculations
d [ A ] [ B ] = 1

# Iterate over the range from A to C for the rows and from B to D for the columns
for i in range ( A , C + 1 ) :
    for j in range ( B , D + 1 ) :
        # Update the value of d[i][j] based on its neighboring cells and some arithmetic operations
        d [ i ] [ j ] += ( d [ i ] [ j - 1 ] * i + d [ i - 1 ] [ j ] * j - d [ i - 1 ] [ j - 1 ] * ( i - 1 ) * ( j - 1 ) ) % m

# Print the value at the bottom-right corner of the array
print ( d [ C ] [ D ] )
