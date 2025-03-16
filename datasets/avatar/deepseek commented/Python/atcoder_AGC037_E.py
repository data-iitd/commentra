
N , K = map ( int , input ( ).split ( ) )
# Read the values of N and K from input
S = input ( )
# Read the string S from input
aaaa = False
# Initialize a flag to check special conditions
if K >= 15 :
    aaaa = True
    # If K is 15 or more, set the flag to True
elif 2 ** K >= N :
    aaaa = True
    # If 2 to the power of K is greater than or equal to N, set the flag to True
if aaaa :
    print ( min ( S ) * N )
    exit ( )
    # If the flag is True, print the minimum character in S multiplied by N and exit
def get_last_dict ( s_str ) :
    U = s_str + s_str [ : : -1 ]
    # Concatenate the string with its reverse
    c = min ( s_str )
    # Find the minimum character in the original string
    p = U.index ( c )
    # Find the index of the minimum character in the concatenated string
    minindex = p
    p += 1
    while p <= N :
        if U [ p ] == c :
            if check_normal_dict ( U , minindex , p ) :
                minindex = p
        p += 1
    return U [ minindex : minindex + N ]
    # Find the lexicographically smallest substring of length N
def check_normal_dict ( u , pointer1 , pointer2 ) :
    for i in range ( N ) :
        if u [ pointer1 + i ] > u [ pointer2 + i ] :
            return True
        elif u [ pointer1 + i ] < u [ pointer2 + i ] :
            return False
    return False
    # Compare two substrings to determine which one is lexicographically smaller
S = get_last_dict ( S )
# Transform the string S using the get_last_dict function
if K == 1 :
    print ( S )
    # If K is 1, print the transformed S
else :
    count = 0
    for c in S :
        if c == S [ 0 ] :
            count += 1
        else :
            break
    # Count the number of times the first character appears in S
    if count * ( 2 ** ( K - 1 ) ) >= N :
        print ( S [ 0 ] * N )
        # If repeating the first character a certain number of times exceeds the length of S, print the first character repeated N times
    else :
        S = S [ 0 ] * ( count * ( ( 2 ** ( K - 1 ) ) - 1 ) ) + S
        # Otherwise, construct a new string by repeating the first character and appending the original S
        print ( S [ 0 : N ] )
        # Print the first N characters of the new string