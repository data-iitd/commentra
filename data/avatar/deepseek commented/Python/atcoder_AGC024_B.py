
def main ( ) :
    # Read the number of elements N
    N = int ( input ( ) )
    # Read the list of integers P
    P = [ int ( input ( ) ) for _ in range ( N ) ]
    # Call the editorial function with N and P as arguments
    editorial ( N , P )

def editorial ( N , P ) :
    # If there is only one element, print 0 and return
    if N == 1 :
        print ( 0 )
        return
    # Initialize an array to store positions of elements in P
    a = [ 0 ] * ( N + 1 )
    # Populate the array with positions of elements in P
    for i , p in enumerate ( P ) :
        a [ p ] = i
    # Initialize temporary and maximum length variables
    tmp = 1
    max_len = 1
    # Iterate through the positions to find the maximum length of consecutive increasing elements
    for i in range ( 1 , N ) :
        if a [ i ] < a [ i + 1 ] :
            tmp += 1
            max_len = max ( max_len , tmp )
        else :
            tmp = 1
    # Calculate the answer as N - max_len
    ans = N - max_len
    # Print the answer
    print ( ans )

def WA ( N , P ) :
    tmp = 0
    ans = 0
    for i , p in enumerate ( P ) :
        if i == 0 or P [ i - 1 ] + 1 == p :
            tmp += 1
        else :
            ans = max ( ans , tmp )
            tmp = 1
    print ( N - ans )

if __name__ == '__main__' :
    main ( )