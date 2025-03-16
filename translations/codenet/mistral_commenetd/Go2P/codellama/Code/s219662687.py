
# Package declaration and importing necessary packages
import math

# Main function declaration and initialization of constants
def main():
    # Large constant value for initializing arrays
    INF = int(math.pow(10, 11))

    # Reading input values from standard input
    A = int(input())
    B = int(input())
    Q = int(input())

    # Initializing arrays s and t with size A+2 and B+2 respectively
    # The first and last elements are initialized with -INF and INF respectively
    s = [-INF] + [int(input()) for _ in range(A)] + [INF]
    t = [-INF] + [int(input()) for _ in range(B)] + [INF]

    # Processing each query
    for _ in range(Q):
        # Reading query value x from standard input
        x = int(input())

        # Finding the indices b and d of array s and t respectively
        # where s[b] and t[d] are the smallest elements greater than x
        b = next((i for i, v in enumerate(s) if v > x), len(s))
        d = next((i for i, v in enumerate(t) if v > x), len(t))

        # Computing the minimum distance between x and any pair of elements S and T
        # from arrays s and t respectively
        res = INF
        for S in (s[b-1], s[b]):
            for T in (t[d-1], t[d]):
                # Computing the absolute difference between S and x, and T and S
                d1, d2 = abs(S-x), abs(T-S)

                # Updating the minimum distance if the current pair has a smaller distance
                res = min(res, min(d1, d2))

        # Printing the minimum distance for the current query
        print(res)

# Helper functions for array manipulation and arithmetic operations
def abs(x):
    return abs(x)

def min(x, y):
    return min(x, y)

def max(x, y):
    return max(x, y)

# END-OF-CODE
