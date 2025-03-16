
import math

def main ( ) : 
    q = int ( input ( ) ) ; # Read the number of queries
    
    while ( q -- > 0 ) : 
        n = int ( input ( ) ) ; # Read the number n for the current query
        s = 0 ; # Initialize the sum variable s
        
        x = int ( math.log ( n ) / math.log ( 2 ) ) ; # Calculate the position of the most significant bit of n
        x += 1 ; # Increment x by 1
        
        s = - 1 * ( long ) math.pow ( 2 , x ) + 2 + ( ( long ) n * ( long ) ( n + 1 ) ) / 2 - ( long ) math.pow ( 2 , x ) ; 
        # Calculate s using arithmetic operations and power functions
        
        print ( s ) ; # Print the result s for the current query


if __name__ == "__main__" : 
    main ( ) ; 


