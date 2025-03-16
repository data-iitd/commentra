import sys
import math
from itertools import permutations

# Constants for buffer sizes and infinity value
initialBufSize = 1e4
maxBufSize = 1e8
INF = 1e8

# Global variables for input/output handling and direction vectors
scanner = sys.stdin.readline
writer = sys.stdout.write
di = [-1, 0, 1, 0]  # Direction vectors for row movement
dj = [0, -1, 0, 1]  # Direction vectors for column movement

def main():
    # Read three integers A, B, C
    A, B, C = map(int, scanner().split())
    
    # Check if C is within the range [A, B] and print the result
    if A <= C <= B:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
