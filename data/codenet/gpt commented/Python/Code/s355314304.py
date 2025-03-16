# Read an integer input from the user
n = int(input())

# Check if the number is a multiple of 1000
if n % 1000 == 0:
    # If it is a multiple of 1000, print 0
    print(0)
else:
    # If it is not a multiple of 1000, calculate and print the difference to the next multiple of 1000
    print(1000 - n % 1000)
