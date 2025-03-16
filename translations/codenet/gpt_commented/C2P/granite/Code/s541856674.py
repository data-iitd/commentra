
# Read two integers from user input
N = int(input())
R = int(input())

# Check if the first input value N is greater than or equal to 10
if N >= 10:
    # If N is 10 or more, print the value of R as is
    print(R)
else:
    # If N is less than 10, calculate and print R adjusted by the difference from 10
    print(R + 100 * (10 - N))

# End of code
