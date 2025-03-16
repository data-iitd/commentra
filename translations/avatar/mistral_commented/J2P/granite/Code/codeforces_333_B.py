

import sys
import math
import bisect
import heapq
from collections import deque
from collections import defaultdict
from collections import Counter
from collections import OrderedDict
from itertools import groupby
from itertools import permutations

def main():
    # Main function declaration

    n, m = map(int, input().split())  # Reading the number of rows and columns in the grid
    banned_rows = set()  # Creating a set to store banned rows
    banned_cols = set()  # Creating a set to store banned columns

    for _ in range(m):
        # Reading banned cells and adding them to the respective sets

        r, c = map(int, input().split())
        if r > 1 and r < n: banned_rows.add(r)  # Adding the row to the set of banned rows
        if c > 1 and c < n: banned_cols.add(c)  # Adding the column to the set of banned columns

    answer = (n - 2) * 2  # Initializing the answer as the total number of cells in the grid minus the banned cells
    answer -= len(banned_rows)  # Subtracting the number of banned rows
    answer -= len(banned_cols)  # Subtracting the number of banned columns

    if n % 2!= 0:
        # Special case when the number of rows is odd

        mid = (n + 1) // 2
        if mid not in banned_rows and mid not in banned_cols:
            # If the middle cell is not banned, decrement the answer
            answer -= 1

    print(answer)  # Printing the answer

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code logic for anyone who reads it.