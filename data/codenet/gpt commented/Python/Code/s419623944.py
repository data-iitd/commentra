# Read two integers N and R from input
N, R = map(int, input().split())

# Check if N is greater than or equal to 10
if N >= 10:
    # If N is 10 or more, print R as is
    print(R)
else:
    # If N is less than 10, calculate and print R plus a penalty based on how much less N is than 10
    print(R + 100 * (10 - N))
