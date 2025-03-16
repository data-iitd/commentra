
n , m = map ( int , input ( ).strip ( ).split ( ) ) # Reading the number of elements and number of queries
out = [ 0 for _ in range ( n ) ] # Initializing the output list with zeros
comp = [ i + 2 for i in range ( n ) ] # Initializing the comparison list with values from 2 to n+1

# Processing each query
for _ in range ( m ) :
    l , r , x = map ( int , input ( ).strip ( ).split ( ) ) # Reading the query parameters
    t = l
    while t <= r :
        next_val = comp [ t - 1 ] # Getting the next value to compare
        if out [ t - 1 ] == 0 and t != x : # Checking if the current position should be updated
            out [ t - 1 ] = x # Updating the output list
        comp [ t - 1 ] = r + 1 if t >= x else x # Updating the comparison list based on the condition
        t = next_val # Moving to the next position in the range

print ( * out ) # Outputting the final result

