
n , m = map ( int , input ( ).split ( ) )
# Read the number of rows and columns
l = [ ]
# Initialize an empty list to store the rows of the grid
for i in range ( n ) :
    # Loop through each row
    s = input ( )
    s = list ( s )
    # Read the row and convert it to a list of characters
    for j in range ( m ) :
        # Loop through each column in the row
        if s [ j ] == '.' :
            # Check if the cell is a dot
            if ( i + j ) & 1 : s [ j ] = 'W'
            # If the sum of row index and column index is odd, color the cell 'W'
            else : s [ j ] = 'B'
            # Otherwise, color the cell 'B'
    l.append ( s )
    # Add the processed row to the list
for c in l : print ( "".join ( c ) )
# Print each row as a string

