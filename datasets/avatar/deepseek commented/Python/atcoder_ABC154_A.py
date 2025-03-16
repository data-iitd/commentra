
import sys
def solve ( S : str , T : str , A : int , B : int , U : str ) :
    # Check if the string S is equal to the string U
    if S == U :
        # Decrement the count of A by 1
        A -= 1
    # Check if the string T is equal to the string U
    if T == U :
        # Decrement the count of B by 1
        B -= 1
    # Print the updated counts of A and B
    print ( A , B )
    return
def main ( ) :
    def iterate_tokens ( ) :
        for line in sys.stdin :
            for word in line.split ( ) :
                yield word
    tokens = iterate_tokens ( )
    # Read the string S
    S = next ( tokens )
    # Read the string T
    T = next ( tokens )
    # Read the integer A
    A = int ( next ( tokens ) )
    # Read the integer B
    B = int ( next ( tokens ) )
    # Read the string U
    U = next ( tokens )
    # Call the solve function with the read inputs
    solve ( S , T , A , B , U )
if __name__ == '__main__' :
    main ( )

