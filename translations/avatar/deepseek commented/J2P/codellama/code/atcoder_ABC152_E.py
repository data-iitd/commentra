
import math
import sys

def main ( ) : 
    N = int ( sys.stdin.readline ( ) ) 
    A = [ int ( sys.stdin.readline ( ) ) for i in range ( N ) ] 
    
    # Initialize LCM to 1
    lcm = 1 
    
    # Calculate the LCM of all elements in array A
    for ai in A : 
        a = ai 
        lcm = lcm // math.gcd ( lcm , a ) * a 
    
    # Define the modulo value
    mod = 1000000007 
    
    # Calculate the LCM modulo 10^9 + 7
    modLcm = lcm % mod 
    
    # Initialize the answer to 0
    ans = 0 
    
    # Calculate the sum of each element in A divided by the LCM, modulo 10^9 + 7
    for ai in A : 
        ans = ( ans + modDiv ( modLcm , ai , mod ) ) % mod 
    
    # Print the final answer
    print ( ans ) 

# Function to perform modular division
def modDiv ( a , b , mod ) : 
    return ( a % mod ) * modInv ( b , mod ) % mod 

# Function to calculate modular inverse
def modInv ( x , mod ) : 
    return modPow ( x , mod - 2 , mod ) 

# Function to perform modular exponentiation
def modPow ( b , e , mod ) : 
    ans = 1 
    x = b % mod 
    for y in range ( e ) : 
        if ( y & 1 ) == 1 : 
            ans = ( ans * x ) % mod 
        x = ( x * x ) % mod 
    return ans 

if __name__ == "__main__" : 
    main ( ) 

# 