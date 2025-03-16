# Initialize variables N and R to zero
N = 0
R = 0

# Read two integers from the standard input
N, R = map(int, input().split())

# Check if N is greater than or equal to 10
if N >= 10:
    # If condition is true, print the value of R
    print(R)
else:
    # If condition is false, print the value of R plus 100 times the difference between 10 and N
    print(R + 100 * (10 - N))

# End of the code
# <END-OF-CODE>
