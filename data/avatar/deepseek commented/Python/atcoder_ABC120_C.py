from collections import deque
from collections import Counter
from itertools import product, permutations, combinations
from operator import itemgetter
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right, bisect
from fractions import gcd
from math import ceil, floor, sqrt, cos, sin, pi, factorial
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

# Main function to solve the problem
def main():
    # Read input string from the user
    s = input()
    
    # Check if all characters in the string are the same
    if len(set(s)) == 1:
        print(0)
        sys.exit()
    
    # Count the frequency of each character in the string
    a = Counter(s)
    
    # Calculate the answer as twice the minimum frequency of any character
    ans = min(a.values()) * 2
    
    # Print the answer and exit
    print(ans)

# Entry point of the script
if __name__ == '__main__':
    main()
