
# Importing packages for input/output operations and utility classes
import java.io.* ;
import java.util.* ;

if __name__ == '__main__' :
    # Initialize the Scanner object to read input
    scn = java.util.Scanner ( System.in ) ;
    
    # Read the size of the array
    n = scn.nextInt ( ) ;
    
    # Initialize the array of size n
    arr = [ ] ;
    
    # Read n integers into the array
    for i in range ( n ) :
        arr.append ( scn.nextInt ( ) ) ;
    
    # Initialize ans with the value of the first element plus 1
    ans = arr [ 0 ] + 1 ;
    
    # Iterate through the array and update ans
    for i in range ( 1, n ) :
        ans += abs ( arr [ i ] - arr [ i - 1 ] ) + 2 ;
    
    # Print the final value of ans
    print ( ans ) ;

