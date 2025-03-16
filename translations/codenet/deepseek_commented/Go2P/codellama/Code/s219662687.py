
import sys
import math

def main():
    INF = 10 ** 11 # Define a large constant for infinity
    A = int(sys.stdin.readline().strip()) # Read the number of temples
    B = int(sys.stdin.readline().strip()) # Read the number of shrines
    Q = int(sys.stdin.readline().strip()) # Read the number of queries
    s = [-INF] + [int(sys.stdin.readline().strip()) for _ in range(A)] + [INF] # Create a list for temples with extra space for boundaries
    t = [-INF] + [int(sys.stdin.readline().strip()) for _ in range(B)] + [INF] # Create a list for shrines with extra space for boundaries
    for i in range(Q): # Loop over queries
        x = int(sys.stdin.readline().strip()) # Read the query point
        b, d = bisect_left(s, x), bisect_left(t, x) # Find closest temples and shrines
        res = INF # Initialize result with infinity
        for S in [s[b-1], s[b]]: # Check previous and current temple
            for T in [t[d-1], t[d]]: # Check previous and current shrine
                d1, d2 = abs(S-x)+abs(T-S), abs(T-x)+abs(S-T) # Calculate distances
                res = min(res, min(d1, d2)) # Update result with minimum distance
        print(res) # Print the minimum distance for the query

def bisect_left(a, x):
    lo, hi = 0, len(a) # Set bounds for binary search
    while lo < hi: # Loop while bounds are not equal
        mid = (lo + hi) // 2 # Calculate midpoint
        if a[mid] < x: # Check if midpoint is less than x
            lo = mid + 1 # Set lower bound to midpoint
        else:
            hi = mid # Set upper bound to midpoint
    return lo # Return lower bound

if __name__ == "__main__":
    main() # Call main function

