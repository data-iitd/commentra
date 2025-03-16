
n , m = map ( int , input ( ).split ( ) )
# Read the dimensions of the grid (n: number of rows, m: number of columns)

c = set ( s.find ( "S" ) - s.find ( "G" ) for s in ( input ( ) for _ in range ( n ) ) )
# For each of the n rows, read the string and find the index of 'S' and 'G'.
# Calculate the difference between the indices of 'S' and 'G' for each row.
# Store these differences in a set 'c'.

print ( - 1 if any ( a < 0 for a in c ) else len ( c ) )
# Check if there is any negative difference in the set 'c'.
# If there is, print '-1'. Otherwise, print the number of unique non-negative differences.
