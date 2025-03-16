
import math
import sys

def main ( ):
    # Step 1: Read the number of points N from the input.
    N = int ( sys.stdin.readline ( ) )
    
    # Step 2: Read the coordinates of each point and store them in arrays x and y.
    x = [ int ( sys.stdin.readline ( ) ) for _ in range ( N ) ]
    y = [ int ( sys.stdin.readline ( ) ) for _ in range ( N ) ]
    
    # Step 3: For each point, calculate the angles between this point and all other points.
    for i in range ( N ):
        thetas = [ ]
        for j in range ( N ):
            if i == j: continue # Skip the point itself
            # Calculate the angle using atan2
            thetas.append ( math.atan2 ( y [ j ] - y [ i ] , x [ j ] - x [ i ] ) )
        
        # Step 4: Sort the angles and add 2π to the last angle to handle the wrap-around.
        thetas.sort ( )
        thetas.append ( thetas [ 0 ] + 2 * math.pi )
        
        # Step 5: Find the maximum difference between consecutive angles, subtract π, and divide by 2π to get the fraction of the circle.
        ans = 0
        for k in range ( N - 1 ):
            ans = max ( ans , thetas [ k + 1 ] - thetas [ k ] - math.pi )
        
        # Step 6: Print the result.
        print ( ans / ( math.pi * 2 ) )

