
def main ( ) :
    # Read the value of K from the user
    K = int ( input ( ) )
    # Read the string S from the user
    S = input ( )
    # Check if the length of S is less than or equal to K
    if len ( S ) <= K :
        # If the length of S is less than or equal to K, return S as it is
        return S
    # If the length of S is greater than K, return the first K characters of S followed by '...'
    return S [ : K ] + '...'
if __name__ == '__main__' :
    # Print the result of the main function
    print ( main ( ) )

