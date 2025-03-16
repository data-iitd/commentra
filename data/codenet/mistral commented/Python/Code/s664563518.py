#######
# Code
#######

# Importing necessary libraries and functions
from heapq import heappush, heappop, heapify
from collections import deque, defaultdict, Counter
import itertools
from itertools import permutations, combinations, accumulate
import sys
import bisect
import string
import math
import time

# Function definitions
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return [int(i) for i in input().split()]
def LI_(): return [int(i)-1 for i in input().split()]
def StoI(): return [ord(i)-97 for i in input()]
def ItoS(nn): return chr(nn+97)
def input(): return sys.stdin.readline().rstrip()
def show(*inp, end='\n'):
    if show_flg:
        print(*inp, end=end)

YN = ['No', 'Yes']
MOD = 10**9+7
inf = float('inf')
IINF = 10**10
l_alp = string.ascii_lowercase
u_alp = string.ascii_uppercase
ts = time.time()
sys.setrecursionlimit(10**6)
nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']

# Global variables and flags
show_flg = False

# Main function
def main():
    # Input the number of strings N
    N = I()

    # Initialize lists s and t of size N
    s = [0] * N
    t = [0] * N

    # Read strings and their corresponding integers from input
    for i in range(N):
        s[i], t[i] = map(str, input().split())
        # Convert the string t[i] to an integer
        t[i] = int(t[i])

    # Read a string X from input
    X = input()

    # Find the index i of the string X in list s
    xi = 0
    for i in range(N):
        if s[i] == X:
            xi = i
            break

    # Initialize variable ans to 0
    ans = 0

    # Iterate through the list t and add the value at the current index to ans if the index is less than xi
    for i in range(N):
        if xi < i:
            ans += t[i]

    # Print the value of ans
    print(ans)

# Run the main function if the script is run as the main program
if __name__ == '__main__':
    main()
