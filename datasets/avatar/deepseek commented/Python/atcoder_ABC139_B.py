
a , b = map ( int , input ( ).split ( ) )
# Taking two integer inputs, `a` and `b`.
hole = 1
i = 0
# Initializing `hole` to 1 and `i` to 0.
check = True
# Setting a boolean variable `check` to `True`.
while check :
    # The `while` loop runs as long as `check` is `True`.
    if hole >= b :
        # Checking if `hole` is greater than or equal to `b`.
        check = False
        # If so, set `check` to `False` to exit the loop.
    else :
        hole = a * ( i + 1 ) - i
        # If `hole` is less than `b`, update `hole` to `a * (i + 1) - i`.
        i += 1
        # Increment `i` by 1.
print ( i )
# Finally, print the value of `i` after the loop exits.

