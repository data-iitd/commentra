# Define a long long type for large integers
from typing import List

# Macro to simplify loop syntax
def rep(i, n):
    return range(n)

def main():
    # Declare variables
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    sum_positive_diff = 0

    # Input the second array 'b' and calculate the sum of positive differences
    for i in rep(n):
        # Check if the difference between corresponding elements of 'a' and 'b' is positive
        if a[i] - b[i] > 0:
            # If positive, add the difference to 'sum'
            sum_positive_diff += a[i] - b[i]

    # Output the final sum of positive differences
    print(sum_positive_diff)

if __name__ == "__main__":
    main()
