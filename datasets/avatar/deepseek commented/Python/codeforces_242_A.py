
x , y , a , b = map ( int , input ( ).split ( ) )
# Taking input values for x, y, a, and b
games = [ ]
# Initializing an empty list called games
for i in range ( a , x + 1 ) :
    # Looping from a to x
    if ( i <= b ) : continue
    # Skipping values of i that are less than or equal to b
    else :
        for j in range ( b , y + 1 ) :
            # Looping from b to y
            if i > j :
                # Checking if i is greater than j
                games.append ( ( i , j ) )
                # Appending the tuple (i, j) to the games list
print ( len ( games ) )
# Printing the length of the games list
for i in games :
    print ( f"{i[0]} {i[1]}" )
# Printing each tuple in the games list

