
k , n , w = input ( ).split ( )
# Taking input for k, n, and w
if 1 <= int ( k ) and int ( w ) <= 1000 :
    # Checking if k and w are within the specified range
    total = 0
    # Initializing total to 0
    for i in range ( 1 , int ( w ) + 1 ) :
        # Looping from 1 to w (inclusive)
        total += i * int ( k )
        # Multiplying the current iteration number by k and adding to total
    if total > int ( n ) :
        # Checking if total is greater than n
        print ( total - int ( n ) )
        # Printing the difference between total and n if total is greater
    else :
        print ( 0 )
        # Printing 0 if total is not greater than n

