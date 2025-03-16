# Take an integer 'n' as input from the user
n = int(input())

# Take 'n' number of integers as input and store them in a list 'l'
l = list(map(int, input().split()))

# Find the maximum number 'b' in the list 'l'
b = max(l)

# Calculate the sum of all numbers in the list 'l' and store it in a variable 's'
s = sum(l)

# Check if the maximum number 'b' is less than the sum of all numbers 's' minus the maximum number 'b'
if b < s - b:
    # If the condition is true, print 'Yes'
    print('Yes')
else:
    # If the condition is false, print 'No'
    print('No')
