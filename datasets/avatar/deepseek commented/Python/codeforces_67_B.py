u = input
n , k = map ( int , u ( ).split ( ) )
# Taking input from the user and splitting it into two integers
# Assigning the values to variables `n` and `k`

M = [ int ( i ) for i in u ( ).split ( ) ]
# Taking another input from the user, which is supposed to be a list of integers
# Converting each input into an integer and storing them in the list `M`

m = 0
# Initializing a variable `m` to 0

for j in range ( n ) :
    # Starting a loop that will iterate `n` times
    for p in range ( n ) :
        # Starting another loop that will iterate `n` times
        if ( 0 == M [ p ] ) :
            # Checking if the element at position `p` in the list `M` is 0
            print ( p + 1 , end = ' ' )
            # If the condition is true, print the position `p + 1`
            break
            # Break out of the loop after printing the position
    for l in range ( p + 1 - k ) : M [ l ] -= 1
    # Decreasing the elements in the list `M` from position 0 to `p - k` by 1
    M [ p ] -= 1
    # Decreasing the element at position `p` by 1