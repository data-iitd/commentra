import sys
import io
import os
import sys
import math
import bisect
import heapq
from collections import defaultdict, deque, Counter
from itertools import permutations, combinations
from functools import lru_cache
from typing import *

input = sys.stdin.readline

def main():
    # Initialize FastReader to read input efficiently
    inp = FastReader()
    
    # Read the number of elements
    n = inp.nextInt()
    
    # Create a TreeSet to keep track of available positions on the left
    left = sortedcontainers.SortedSet()
    
    # Initialize an array to store the answers
    answer = [0] * n
    
    # Populate the TreeSet with indices from 0 to n-1
    for i in range(n):
        left.add(i)
    
    # Read the number of queries
    q = inp.nextInt()
    
    # Process each query
    for _ in range(q):
        # Read the range [l, r] and the winning index
        l = inp.nextInt() - 1
        r = inp.nextInt() - 1
        win = inp.nextInt() - 1
        
        # Update the answer array for all positions in the range [l, r]
        idx = left.bisect_left(l)
        while idx < len(left) and left[idx] <= r:
            curr = left[idx]
            answer[curr] = win
            left.discard(curr)
            idx += 1
        
        # Mark the winning index as available again
        answer[win] = 0
        left.add(win)
    
    # Build the output string from the answer array
    ans = ''.join(str(x) for x in answer)
    
    # Print the final answer
    print(ans)

class FastReader:
    def __init__(self):
        self.buffer = io.BytesIO(os.read(0, os.fstat(0).st_size))
        self.tokens = []
    
    def next(self):
        while not self.tokens:
            line = self.buffer.readline().decode('utf-8')
            self.tokens = line.split()
        return self.tokens.pop(0)
    
    def nextInt(self):
        return int(self.next())
    
    def nextLong(self):
        return int(self.next())
    
    def nextDouble(self):
        return float(self.next())
    
    def nextLine(self):
        return self.buffer.readline().decode('utf-8')

if __name__ == "__main__":
    main()
