# Read input values for N, M, X, and Y
N, M, X, Y = map(int, input().split())

# Read the list of integers x from input, representing the first group
x = list(map(int, input().split()))

# Read the list of integers y from input, representing the second group
y = list(map(int, input().split()))

# Determine if there is a possibility of war or peace based on the maximum and minimum values
# If the maximum value in group x is less than the minimum value in group y, print 'No War'
# Otherwise, print 'War'
print('No War' if max(max(x), X) < min(min(y), Y) else 'War')
