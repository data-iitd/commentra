
t , s , q = map ( int , input ( ).split ( ) )
# Taking three integer inputs and assigning them to variables t, s, and q

ans = 0
# Initializing the variable ans to 0

while ( s < t ) :
    # Starting a while loop that continues as long as s is less than t
    s *= q
    # Multiplying s by q
    ans += 1
    # Incrementing ans by 1

print ( ans )
# Printing the final value of ans after the loop completes

