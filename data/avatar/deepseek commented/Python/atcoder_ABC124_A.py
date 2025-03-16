
a , b = map ( int , input ( ).split ( ) )
# Taking two integer inputs, `a` and `b`, separated by spaces

c = 0
# Initializing a variable `c` to 0

for i in range ( 2 ) :
    # The loop runs twice
    c += max ( a , b )
    # Adding the maximum of `a` and `b` to `c`
    if a >= b :
        # Checking if `a` is greater than or equal to `b`
        a -= 1
        # Decrementing `a` by 1 if the condition is true
    else :
        b -= 1
        # Decrementing `b` by 1 if the condition is false

print ( c )
# Printing the value of `c` after the loop completes

