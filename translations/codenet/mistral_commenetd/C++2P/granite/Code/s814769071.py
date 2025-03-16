

#pragma region
import sys
import math
import bisect
import heapq
from collections import deque
from collections import defaultdict
from collections import Counter
from itertools import combinations
from itertools import permutations
input = lambda: sys.stdin.readline().rstrip()
rs = lambda: input().split()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
# Macro for easier looping
def rep(i, s, e):
    for i in range(s, e):
def rrep(i, s):
    for i in range(s-1, -1, -1):
def all(x):
    return x.begin(), x.end()
#pragma endregion

def main():
    # Initialize variables
    n, k = map(int, input().split())
    MOD = 10**9 + 7

    # Calculate the maximum number of unique elements in a subset of size k from 1 to n
    mx = n * (n + 1) // 2 - (n - k)*(n - k + 1) // 2

    # Calculate the minimum number of unique elements in a subset of size k from 1 to n
    mn = k * (k - 1) // 2

    # Initialize result variable
    res = 0

    # Iterate through all possible subset sizes from k to n+1
    for i in range(k, n + 2):
        # Calculate the number of unique elements in the current subset
        res += mx - mn + 1

        # Update the maximum and minimum number of unique elements for the next iteration
        mx += n - i
        mn += i

        # Update the result variable
        res %= MOD

    # Print the final result
    print(res)

if __name__ == "__main__":
    main()

