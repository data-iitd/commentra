from collections import defaultdict, deque
from functools import lru_cache
from heapq import heappush, heappop
from typing import Counter
from bisect import bisect_right, bisect_left
import math

# Aliasing heapq functions for convenience
hpop = heappop
hpush = heappush

def solution():
    # Read the first line of input which represents the colors bought
    line = input()
    # Count the occurrences of each color bought using Counter
    bought_count = Counter(line)
    
    # Read the second line of input which represents the colors made
    line = input()
    # Count the occurrences of each color made using Counter
    made_count = Counter(line)
    
    # Initialize the result variable to store the total count of matched colors
    res = 0
    
    # Iterate through each color in the made_count
    for color in made_count:
        # If a color made is not found in the bought colors, return -1
        if color not in bought_count:
            return print(-1)
        # Add the minimum of the bought and made counts for each color to the result
        res += min(bought_count[color], made_count[color])
    
    # Print the total count of matched colors
    print(res)

def main():
    # Set the number of test cases (currently set to 1)
    t = 1
    # Loop through each test case
    for _ in range(t):
        solution()

# Entry point of the program
main()
