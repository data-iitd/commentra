# Declare an integer variable to hold the input value
n = int(input())

# Check if n is a multiple of 1000
if n % 1000 == 0:
    # If true, print 0 since no additional amount is needed to reach the next multiple of 1000
    print(0)
else:
    # If false, calculate and print the difference to the next multiple of 1000
    print((n // 1000 + 1) * 1000 - n)

# <END-OF-CODE>
