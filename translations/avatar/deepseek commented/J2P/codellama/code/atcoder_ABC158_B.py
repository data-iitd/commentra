
import math
import sys

N = int(sys.stdin.readline())
A = int(sys.stdin.readline())
B = int(sys.stdin.readline())
k = 0

# Check if the values of N, A, and B are within the specified ranges
if 1 <= N <= math.pow(10, 18) and 0 <= A <= math.pow(10, 18) and 0 <= B <= math.pow(10, 18) and 0 < A + B <= math.pow(10, 18):

    # Calculate the number of complete cycles (k) of A and B that fit into N
    if A + B <= N:
        k = N // (A + B)
        if N - k * (A + B) > A:
            print(A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)))
        else:
            print(A * k + (N - k * (A + B)))
    # If the sum of A and B is greater than N and A is less than or equal to N
    elif A + B > N and A <= N:
        print(A)
    # If none of the above conditions are met, print N
    else:
        print(N)

# 