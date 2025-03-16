# Read an integer from the user
n = int(input())

# Check if n is divisible by 1000
if n % 1000 == 0:
    # If n is divisible by 1000, print 0
    print(0)
else:
    # If n is not divisible by 1000, calculate the difference
    # between the next multiple of 1000 and n, and print that difference
    print((n // 1000 + 1) * 1000 - n)

# <END-OF-CODE>
