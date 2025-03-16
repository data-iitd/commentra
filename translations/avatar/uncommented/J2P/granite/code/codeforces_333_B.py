
import sys
import math
import bisect
import heapq
from collections import deque
from collections import defaultdict
from collections import Counter
from collections import OrderedDict
from itertools import permutations
from itertools import combinations

def main():
    n, m = map(int, input().split())
    banned_rows = set()
    banned_cols = set()
    for _ in range(m):
        r, c = map(int, input().split())
        if r > 1 and r < n:
            banned_rows.add(r)
        if c > 1 and c < n:
            banned_cols.add(c)
    ans = (n - 2) * 2
    ans -= len(banned_rows)
    ans -= len(banned_cols)
    if n % 2!= 0:
        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            ans -= 1
    print(ans)

if __name__ == "__main__":
    main()

