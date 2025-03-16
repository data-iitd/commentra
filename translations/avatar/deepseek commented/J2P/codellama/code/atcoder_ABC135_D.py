import sys ; 

def main ( ) : 
    # MOD constant with value 10^9 + 7
    MOD = 1000000007 ; 

    # Main logic of the program
    sc = sys.stdin.readline ( ) ; 
    cs = list ( sc ) ; 

    # 2D array dp to store the number of ways to achieve each remainder when the number is divided by 13
    dp = [ [ 0 for _ in range ( 13 ) ] for _ in range ( len ( cs ) ) ] ; 

    # Initialize the base variable to represent the current power of 10
    base = 1 ; 

    # Loop through the character array from the least significant digit to the most significant digit
    for i in range ( len ( cs ) ) : 
        if cs [ len ( cs ) - 1 - i ] == '?' : 
            # If the current character is '?', we iterate through all possible digits (0-9)
            for pre in range ( 13 ) : 
                for next in range ( 10 ) : 
                    dp [ i ] [ ( base * next + pre ) % 13 ] += ( i > 0 ? dp [ i - 1 ] [ pre ] : ( pre == 0 ? 1 : 0 ) ) ; 
                    dp [ i ] [ ( base * next + pre ) % 13 ] %= MOD ; 
        else : 
            # If the current character is not '?', we update the dp array based on the actual digit
            next = ord ( cs [ len ( cs ) - 1 - i ] ) - ord ( '0' ) ; 
            for pre in range ( 13 ) : 
                dp [ i ] [ ( base * next + pre ) % 13 ] += ( i > 0 ? dp [ i - 1 ] [ pre ] : ( pre == 0 ? 1 : 0 ) ) ; 
                dp [ i ] [ ( base * next + pre ) % 13 ] %= MOD ; 
        # Update the base variable to the next power of 10 modulo 13
        base = base * 10 % 13 ; 

    # Print the number of ways to achieve the remainder 5 when the number is divided by 13
    print ( dp [ len ( cs ) - 1 ] [ 5 ] ) ; 

if __name__ == "__main__" : 
    main ( ) ; 

# 