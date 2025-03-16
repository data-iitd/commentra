N , K = map ( int , input ( ).split ( ) ) # Reading N and K
A = list ( map ( int , input ( ).split ( ) ) ) # Reading list A
A.sort ( ) # Sorting the list A

# Binary search setup
ll = - 10 ** 18 - 1 # Lower limit initialized to a very small number
rr = 10 ** 18 + 1 # Upper limit initialized to a very large number

# Binary search execution
while ll + 1 < rr :
    x = ( ll + rr ) // 2 # Calculating the midpoint of the current range
    tot = 0 # Initializing the total count of valid pairs
    
    # Counting valid pairs for each element in A
    for i in range ( N ) :
        if A [ i ] < 0 :
            l = - 1
            r = N
            while l + 1 < r :
                c = ( l + r ) // 2
                if A [ i ] * A [ c ] < x :
                    r = c
                else :
                    l = c
            tot += N - r # Updating the total count for negative A[i]
        else :
            l = - 1
            r = N
            while l + 1 < r :
                c = ( l + r ) // 2
                if A [ i ] * A [ c ] < x :
                    l = c
                else :
                    r = c
            tot += r # Updating the total count for non-negative A[i]
        
        if A [ i ] * A [ i ] < x :
            tot -= 1 # Adjusting for the pair (i, i) if necessary
    
    tot //= 2 # Dividing by 2 to correct for double-counting pairs
    
    # Adjusting the search range based on the total count
    if tot < K :
        ll = x
    else :
        rr = x

print ( ll ) # Output the result
