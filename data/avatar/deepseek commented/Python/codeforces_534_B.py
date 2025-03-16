
v1 , v2 = input ( ).split ( )
# Taking two inputs from the user, splitting them, and converting them into integers
v1 = int ( v1 )
v2 = int ( v2 )
t = int ( input ( ) )
d = int ( input ( ) )

# Initializing variables
a = 1
v = v1
distance = 0

# Entering a loop that runs `t` times
for i in range ( t ) :
    # Checking if the current speed `v` minus `v2` is greater than `(t - i - 1) * d`
    if v - v2 > ( t - i - 1 ) * d :
        a *= - 1
        v = ( t - i - 1 ) * d + v2
    # Adding the current speed `v` to `distance`
    distance += v
    # Updating the speed by adding `a * d` to it
    v += a * d

# Printing the total `distance`
print ( distance )


