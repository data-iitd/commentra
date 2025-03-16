
n , m = map ( int , input ( ).split ( ) )
# Taking input for two integers, `n` and `m`, separated by spaces

if n < 1 :
    # Check if `n` is less than 1
    if m < 1 :
        # Check if `m` is also less than 1
        print ( n , m )
        quit ( )
        # Print `n` and `m` and then quit the program
    print ( "Impossible" )
    quit ( )
    # Print "Impossible" and then quit the program

if m > n :
    # Check if `m` is greater than `n`
    min = m
    max = n + m - 1
    print ( min , max )
    # Calculate `min` as `m` and `max` as `n + m - 1`, then print `min` and `max`

if m <= n :
    # Check if `m` is less than or equal to `n`
    min = n
    max = n + m - 1
    if m == 0 :
        max = n
    print ( min , max )
    # Calculate `min` as `n` and `max` as `n + m - 1`. If `m` is 0, set `max` to `n`. Finally, print `min` and `max`

