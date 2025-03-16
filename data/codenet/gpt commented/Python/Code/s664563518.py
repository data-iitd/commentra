from heapq import heappush, heappop, heapify
from collections import deque, defaultdict, Counter
import itertools
from itertools import permutations, combinations, accumulate
import sys
import bisect
import string
import math
import time

# Function to read an integer from input
def I(): return int(input())

# Function to read multiple integers from input
def MI(): return map(int, input().split())

# Function to read a list of integers from input
def LI(): return [int(i) for i in input().split()]

# Function to read a list of integers from input and decrement each by 1
def LI_(): return [int(i)-1 for i in input().split()]

# Function to convert a string of lowercase letters to their corresponding integer values (0-25)
def StoI(): return [ord(i)-97 for i in input()]

# Function to convert an integer (0-25) back to a lowercase letter
def ItoS(nn): return chr(nn+97)

# Function to read a line of input and strip whitespace
def input(): return sys.stdin.readline().rstrip()

# Function to conditionally print output based on the show_flg flag
def show(*inp, end='\n'):
    if show_flg:
        print(*inp, end=end)

# Constants for output formatting and limits
YN = ['No', 'Yes']
MOD = 10**9+7
inf = float('inf')
IINF = 10**10
l_alp = string.ascii_lowercase
u_alp = string.ascii_uppercase
ts = time.time()
sys.setrecursionlimit(10**6)
nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']

# Flag to control output display
show_flg = False
# show_flg = True

def main():
    # Read the number of entries
    N = I()
    s = [0] * N  # List to store string inputs
    t = [0] * N  # List to store integer inputs

    # Read N pairs of (string, integer) from input
    for i in range(N):
        s[i], t[i] = map(str, input().split())
        t[i] = int(t[i])  # Convert the second element to an integer

    # Read the target string to search for
    X = input()
    xi = 0  # Initialize index for the target string

    # Find the index of the target string X in the list s
    for i in range(N):
        if s[i] == X:
            xi = i  # Store the index where the target string is found
            break

    ans = 0  # Initialize the answer variable

    # Calculate the sum of integers t[i] for all indices greater than xi
    for i in range(N):
        if xi < i:
            ans += t[i]  # Add the value to the answer if index is greater than xi

    # Print the final answer
    print(ans)

# Entry point of the program
if __name__ == '__main__':
    main()
