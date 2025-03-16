# Define the root function to find the root of a given element in a disjoint set
root = lambda x : x if par [ x ] == x else root ( par [ x ] )

# Define the same function to check if two elements are in the same set
same = lambda x , y : root ( x ) == root ( y )

# Define the unite function to merge two sets containing the given elements
def unite ( * z ) :
    x , y = map ( root , z )
    if x != y :
        if rank [ x ] < rank [ y ] :
            par [ x ] = y
            size [ y ] += size [ x ]
        else :
            par [ y ] = x
            size [ x ] += size [ y ]
            if rank [ x ] == rank [ y ] : rank [ x ] += 1

# Read the input, initialize the disjoint set, and process the array
n , * a = map ( int , open ( 0 ).read ( ).split ( ) )
* par , = range ( n )
rank = [ 1 ] * n
size = [ 1 ] * n
b = [ 0 ] * n
for i , t in enumerate ( a ) : b [ t - 1 ] = i
c = 0

# Process the array in reverse order to calculate the result
for k in b [ : : -1 ] :
    l = r = 1
    if k > 0 and a [ k - 1 ] > a [ k ] :
        l += size [ root ( k - 1 ) ]
        unite ( k - 1 , k )
    if k + 1 < n and a [ k + 1 ] > a [ k ] :
        r += size [ root ( k + 1 ) ]
        unite ( k + 1 , k )
    c += l * r * a [ k ]

# Print the final result
print ( c )
