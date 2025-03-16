import sys
import io
import cProfile
import pstats
import io
import os
import time

magic = 1000000007

def find(n, p):
    return 1 if n in p else 0

def solve():
    # Create an Io instance for reading input
    input_stream = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    io_instance = io.Scanner(input_stream)

    # Parse input using the NextInt function of the Io instance
    X = io_instance.NextInt()
    N = io_instance.NextInt()
    p = [io_instance.NextInt() for _ in range(N)]

    # Check if X or its neighbors are present in the p slice
    for i in range(101):
        if find(X - i, p) == 1:
            print(X - i)
            sys.exit(0)
        if find(X + i, p) == 1:
            print(X + i)
            sys.exit(0)

    # Output generation part is not present in the code
    # ans = 0
    # print(ans)

    # If ans > 0, print "Yes" and exit; otherwise, print "No"
    # if ans > 0:
    #   print("Yes")
    # else:
    #   print("No")

# main function initializes flags for CPU and memory profiling and calls the solve function
if __name__ == "__main__":
    # Parse command-line arguments
    # (Assuming command-line arguments are not used in Python version)

    # Call the solve function
    solve()

