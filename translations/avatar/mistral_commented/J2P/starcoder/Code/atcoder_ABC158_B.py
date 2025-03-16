
import sys

# Reading the first long integer `N` from the standard input
N = int(sys.stdin.readline())

# Reading the second long integer `A` from the standard input
A = int(sys.stdin.readline())

# Reading the third long integer `B` from the standard input
B = int(sys.stdin.readline())

# Initializing a long variable `k` with the value 0
k = 0

# Checking if the input values are valid
if ( 1 <= N and N <= pow(10, 18) and 0 <= A and 0 <= B and 0 < A + B and A + B <= pow(10, 18) ):
    # Checking if the sum of `A` and `B` is less than or equal to `N`
    if ( A + B <= N ):
        # Calculating the number of times `A + B` can be added to `N` and storing the result in `k`
        k = N // ( A + B )

        # Checking if the remaining part of `N` after subtracting `k * (A + B)` is greater than `A`
        if ( N - k * ( A + B ) > A ):
            # Printing the result of the expression `A * k + (N - k * (A + B)) - (N - (k * (A + B) + A))`
            print(A * k + (N - k * (A + B)) - (N - (k * (A + B) + A)))
        else:
            # Printing the result of the expression `A * k + (N - k * (A + B))`
            print(A * k + (N - k * (A + B)))
    # Checking if the sum of `A` and `B` is greater than `N`, but `A` is less than or equal to `N`
    elif ( A + B > N and A <= N ):
        # Printing the value of `A`
        print(A)
    # If neither of the above conditions is true
    else:
        # Printing the value of `N`
        print(N)

# 