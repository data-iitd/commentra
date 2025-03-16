
n , m = map ( int , input ( ).split ( ) )
# Read two integers n and m from input

sa = input ( ).count ( "-" )
# Count the number of '-' characters in the input

sa = min ( [ n - sa , sa ] )
# Set sa to the minimum of n - sa and sa, possibly normalizing sa

ss = [ ]
# Initialize an empty list to store results

for _ in range ( m ) :
    a , b = map ( int , input ( ).split ( ) )
    # Read two integers a and b in each iteration of the loop
    
    b -= a
    # Subtract a from b
    
    if ( b % 2 and b <= sa << 1 ) :
        # Check if b is odd and within certain bounds
        ss.append ( "1\n" )
        # Append "1\n" to ss if condition is met
    else :
        ss.append ( "0\n" )
        # Append "0\n" to ss otherwise

print ( "".join ( ss ) )
# Join and print the contents of ss

