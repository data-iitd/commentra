# Read an integer input from the user
n = int(input())

# Read a string input from the user
s = input()

# Check if the length of the string is odd
if n % 2 != 0:
    # If the length is odd, print 'No' since it cannot be split into two equal halves
    print('No')
# Check if the first half of the string is equal to the second half
elif s[:int(n / 2)] == s[int(n / 2):]:
    # If both halves are equal, print 'Yes'
    print('Yes')
else:
    # If the halves are not equal, print 'No'
    print('No')
