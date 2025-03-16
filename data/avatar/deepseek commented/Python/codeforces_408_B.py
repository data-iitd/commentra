
from collections import defaultdict , deque
from functools import lru_cache
from heapq import heappush , heappop
from typing import Counter
from bisect import bisect_right , bisect_left
import math

# Helper functions to pop and push elements from/to the heap
hpop = heappop
hpush = heappush

def solution ( ) :
    # Read the first line of input and create a Counter object for the bought colors
    line = input ( )
    bought_count = Counter ( line )
    
    # Read the second line of input and create a Counter object for the colors to be made
    line = input ( )
    made_cout = Counter ( line )
    
    # Initialize the result variable to store the total number of colors that can be made
    res = 0
    
    # Iterate over each color in the 'made_cout' Counter
    for color in made_cout :
        # Check if the color is not in the 'bought_count' Counter
        if color not in bought_count :
            # If a color is not bought, print -1 and exit
            return print ( - 1 )
        # Calculate the minimum of the counts of the current color in both 'bought_count' and 'made_cout'
        # and add this to the result
        res += min ( bought_count [ color ] , made_cout [ color ] )
    
    # Print the final result
    print ( res )

def main ( ) :
    # Set the number of test cases to 1
    t = 1
    # Run the solution function for one test case
    for _ in range ( t ) :
        solution ( )

