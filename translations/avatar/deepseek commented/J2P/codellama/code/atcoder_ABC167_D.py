
import sys 

def doIt ( ) : 
    # Read the number of elements N and the value K
    N , K = map ( int , input ( ).split ( ) ) 
    
    # Read the array A with N elements, adjusting each element by -1 for 0-based indexing
    A = [ int ( x ) - 1 for x in input ( ).split ( ) ] 
    
    # Set to track visited indices
    used = set ( ) 
    
    # Arrays to store index and position information
    idx = [ 0 ] * N 
    pos = [ 0 ] * N 
    
    # Initialize variables for cycle detection
    next = 0 
    cur = 0 
    
    # Detect the cycle in the array A
    while next not in used : 
        used.add ( next ) 
        idx [ next ] = cur 
        pos [ cur ] = next 
        next = A [ next ] 
        cur += 1 
    
    # Calculate the length of the cycle and adjust the position based on K
    a = cur - idx [ next ] 
    b = idx [ next ] 
    ans = ( 10000 * a + K - b ) % a + b 
    
    # Adjust the answer if necessary based on the cycle length
    if b > K : 
        ans = K 
    
    # Output the final position
    print ( pos [ ans ] + 1 ) 

if __name__ == "__main__" : 
    doIt ( ) 

