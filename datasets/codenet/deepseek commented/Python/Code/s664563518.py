from heapq import heappush, heappop, heapify
from collections import deque, defaultdict, Counter
import itertools
from itertools import permutations, combinations, accumulate
import sys
import bisect
import string
import math
import time

# Function to read an integer input
def I(): return int(input())

# Function to read a space-separated list of integers
def MI(): return map(int, input().split())

# Function to read a list of integers from input
def LI(): return [int(i) for i in input().split()]

# Function to read a list of integers from input, decrementing by 1
def LI_(): return [int(i)-1 for i in input().split()]

# Function to convert a string input to a list of integers representing alphabetical positions
def StoI(): return [ord(i)-97 for i in input()]

# Function to convert an integer back to a string character
def ItoS(nn): return chr(nn+97)

# Function to read a single line of input, stripped of trailing whitespace
def input(): return sys.stdin.readline().rstrip()

# Function to print debug statements if show_flg is True
def show(*inp, end='\n'):
    if show_flg:
        print(*inp, end=end)

# Constants
YN = ['No', 'Yes']
MOD = 10**9+7
inf = float('inf')
IINF = 10**10
l_alp = string.ascii_lowercase
u_alp = string.ascii_uppercase
ts = time.time()
sys.setrecursionlimit(10**6)
nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']

# Flag to control debug print statements
show_flg = False
# show_flg = True

# Main function to execute the program logic
def main():
    # Read the number of elements
    N = I()
    # Initialize lists to store strings and integers
    s = [0] * N
    t = [0] * N

    # Read N pairs of strings and integers
    for i in range(N):
        s[i], t[i] = map(str, input().split())
        t[i] = int(t[i])

    # Read the target string X
    X = input()
    xi = 0

    # Find the index of the target string X
    for i in range(N):
        if s[i] == X:
            xi = i
            break

    ans = 0

    # Sum the integers following the index of X
    for i in range(N):
        if xi < i:
            ans += t[i]

    # Print the result
    print(ans)

# Check if the script is the main module and execute the main function
if __name__ == '__main__':
    main()
