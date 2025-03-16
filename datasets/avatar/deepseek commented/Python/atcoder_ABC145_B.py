# Take an integer input from the user
n = int(input())

# Take a string input from the user
s = input()

# Check if n is odd
if n % 2 != 0:
    # Print 'No' if n is odd
    print('No')
# If n is even, compare the first half of the string with the second half
elif s[:int(n/2)] == s[int(n/2):]:
    # Print 'Yes' if the first half is equal to the second half
    print('Yes')
else:
    # Print 'No' if the first half is not equal to the second half
    print('No')
