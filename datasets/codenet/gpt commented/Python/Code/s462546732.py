# Read two space-separated values from user input
a, b = input().split(" ")

# Convert the input strings to integers
a = int(a)
b = int(b)

# Check if the first integer 'a' is less than or equal to the second integer 'b'
if a <= b:
    # If 'a' is less than or equal to 'b', print 'a'
    print(a)
else:
    # If 'a' is greater than 'b', print 'a' minus 1
    print(a - 1)
