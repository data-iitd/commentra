
import sys
import itertools

def solve ( N : int , x : "List[int]" , y : "List[int]" ) :
    # Generate a list of indices from 0 to N-1
    indices = [ i for i in range ( N ) ]
    
    # Generate all permutations of the indices
    permutations = itertools.permutations ( indices )
    
    # Initialize a list to store the total distances for each permutation
    distances = [ ]
    
    # Iterate over each permutation
    for permutation in permutations :
        # Initialize the total distance for the current permutation
        total_distance = 0
        
        # Calculate the distance between consecutive points in the permutation
        for i in range ( 0 , N - 1 ) :
            f , t = permutation [ i : i + 2 ]
            distance = ( ( x [ t ] - x [ f ] ) ** 2 + ( y [ t ] - y [ f ] ) ** 2 ) ** 0.5
            total_distance += distance
        
        # Append the total distance of the current permutation to the distances list
        distances.append ( total_distance )
    
    # Calculate the average distance by averaging all stored distances
    result = sum ( distances ) / len ( distances )
    
    # Print the result
    print ( result )
    
    # Return from the function
    return

def main ( ) :
    # Function to iterate over tokens in the input
    def iterate_tokens ( ) :
        for line in sys.stdin :
            for word in line.split ( ) :
                yield word
    
    # Get the tokens from the input
    tokens = iterate_tokens ( )
    
    # Read the number of points N
    N = int ( next ( tokens ) )
    
    # Initialize lists for x and y coordinates
    x = [ int ( ) ] * ( N )
    y = [ int ( ) ] * ( N )
    
    # Read the x and y coordinates for each point
    for i in range ( N ) :
        x [ i ] = int ( next ( tokens ) )
        y [ i ] = int ( next ( tokens ) )
    
    # Call the solve function with the input values
    solve ( N , x , y )

if __name__ == "__main__" :
    main ( )

