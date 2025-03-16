#######
# Import necessary libraries
#######

from collections import defaultdict, deque, Counter
from functools import lru_cache
from heapq import heappush, heappop
import math

# Define helper functions
def hpop(heap): return heappop(heap)
def hpush(heap, item): return heappush(heap, item)

#######
# Function to find the solution
#######

def solution():
    # Read the first line and count the number of occurrences of each color
    line = input()
    bought_count = Counter(line)

    # Read the second line and count the number of occurrences of each color
    line = input()
    made_cout = Counter(line)

    # Initialize result to 0
    res = 0

    # Iterate through each color in made_cout
    for color in made_cout:
        # Check if the color is present in bought_count
        if color not in bought_count:
            # If not, print -1 and exit the function
            return print(-1)

        # Update the result by adding the minimum of bought and made counts
        res += min(bought_count[color], made_cout[color])

    # Print the result
    print(res)

#######
# Main function to run the solution function for multiple test cases
#######

def main():
    # Read the number of test cases
    t = int(input())

    # Run the solution function for each test case
    for _ in range(t):
        solution()

# Run the main function
main()
