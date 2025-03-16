
import sys

def main ( ): 
    # Step 1: Read the number of elements N from the standard input
    N = int ( sys.stdin.readline ( ) ) 
    
    # Step 2: Read N integers from the standard input and add them to the list L
    L = [ ] 
    for i in range ( N ): 
        L.append ( int ( sys.stdin.readline ( ) ) ) 
    
    # Step 3: Sort the list L in ascending order
    L.sort ( ) 
    
    # Step 4: Initialize a counter to zero
    count = 0 
    
    # Step 5: Use two nested loops to iterate through the list L, selecting pairs of elements (a, b) where a < b
    for i in range ( N ): 
        for j in range ( i + 1 , N ): 
            a = L [ i ] 
            b = L [ j ] 
            
            # Step 6: For each pair (a, b), call the find method to determine the number of elements in the list L
            # that are greater than a + b and are located after the index j+1
            res = find ( L , j + 1 , a + b ) 
            
            # Step 7: Add the result of the find method to the counter count
            count = count + res 
    
    # Step 8: After all pairs have been processed, print the value of count
    print ( count ) 

def find ( L , from , target ): 
    low = from 
    upp = len ( L ) - 1 
    mid = ( upp - low + 1 ) % 2 == 0 and ( low + upp ) / 2 + 1 or ( low + upp ) / 2 
    
    if ( upp - low < 0 ): 
        return 0 
    elif ( L [ from ] >= target ): 
        return 0 
    elif ( L [ upp ] < target ): 
        return upp - low + 1 
    
    while ( upp - low > 1 ): 
        if ( L [ mid ] >= target ): 
            upp = mid 
        else: 
            low = mid 
        mid = ( upp - low + 1 ) % 2 == 0 and ( low + upp ) / 2 + 1 or ( low + upp ) / 2 
    
    return low - from + 1 

if __name__ == "__main__": 
    main ( ) 

