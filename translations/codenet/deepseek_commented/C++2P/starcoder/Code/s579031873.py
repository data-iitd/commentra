
# Include header for limit values
from sys import maxsize as maxint
# Include header for mathematical functions
from math import ceil
# Include header for standard input/output functions
from sys import stdin, stdout
# Include header for general utilities
from collections import deque
# Include header for standard algorithms
from bisect import bisect_left, bisect_right
# Include header for floating-point limits
from sys import float_info
# Include header for complex number operations
from cmath import phase
# Include header for functional programming
from functools import reduce
# Include header for input/output streams
from io import StringIO
# Include header for associative arrays
from collections import defaultdict
# Include header for queue operations
from queue import PriorityQueue
# Include header for set operations
from bisect import bisect_left, bisect_right, insort_left, insort_right
# Include header for stack operations
from collections import deque
# Include header for string operations
from string import ascii_lowercase, ascii_uppercase, digits
# Include header for unordered associative arrays
from collections import OrderedDict
# Include header for vector operations
from bisect import bisect_left, bisect_right, insort_left, insort_right
from itertools import accumulate, chain, combinations, combinations_with_replacement, compress, count, cycle, dropwhile, filterfalse, groupby, islice, permutations, product, repeat, starmap, takewhile, zip_longest

# Define a type alias for long long
ll = int
# Define a type alias for unsigned long long
ull = int
# Define a type alias for a pair of long long
P = tuple[ll, ll]

# Declare a 2D vector of long long
table = []
# Declare a vector of pairs
roads = []
# Declare a vector of pairs
qs = []

# Define the main function
def main():
  # Declare variables to store the number of elements and the target value
  N, X = map(int, stdin.readline().split())
  # Read the values of N and X from the standard input

  # Initialize the answer variable
  ans = 0
  # Initialize the minimum value variable
  min = maxint
  for i in range(N):
    # Declare a temporary variable to store each input value
    tmp = int(stdin.readline())
    # Read the value into the temporary variable
    X -= tmp
    # Increment the answer count
    ans += 1
    # Update the minimum value if the current value is smaller
    if tmp < min: min = tmp
  # Calculate the final answer by adding the quotient of X divided by the minimum value
  ans += X // min

  # Print the final answer to the standard output
  stdout.write(str(ans) + '\n')

  return 0

# Call the main function
if __name__ == '__main__':
  main()

