# Read an integer value from the user
n = int(input())

# Read a string value from the user
s = input()

# Check if n is odd
if n % 2 != 0:
    print('No')

# Check if the first half of the string is equal to the second half
elif s[:int(n/2)] == s[int(n/2):]:
    print('Yes')

# If the first half is not equal to the second half, print 'No'
else:
    print('No')