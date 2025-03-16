
s , l = ( input ( ) , 2019 )
# Take input string `s` and the number `l` (2019 in this case)
m , a , r = ( [ 1 ] + [ 0 ] * l , 0 , 0 )
# Initialize list `m` with a length of `l` (2019), filled with zeros, and prepends a 1 at the beginning.
for i , e in enumerate ( s [ : : - 1 ] ) :
    # Iterate over the reversed string `s` in steps of 1
    a += int ( e ) * pow ( 10 , i , l )
    # Calculate the value of the character's position times 10 raised to the power of its position in the reversed string, modulo `l`.
    # Add this value to a running total `a`.
    r += m [ a % l ]
    # Increment the running total `r` by the current value in `m` at the position `a % l`.
    m [ a % l ] += 1
    # Increment the value in `m` at the position `a % l` by 1.
print ( r )
# Finally, print the value of `r`.

