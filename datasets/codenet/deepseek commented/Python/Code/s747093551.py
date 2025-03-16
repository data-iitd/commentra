
N, M, X, Y = map(int, input().split())  # Read the number of elements in each list and the two integers
# N: Number of elements in list x
# M: Number of elements in list y
# X: Integer used for comparison with elements in list x
# Y: Integer used for comparison with elements in list y

x = list(map(int, input().split()))  # Read the list of integers for list x
# x: List of integers representing the first list

y = list(map(int, input().split()))  # Read the list of integers for list y
# y: List of integers representing the second list

# Check if there is no war between the two lists
print('No War' if max(max(x), X) < min(min(y), Y) else 'War')
# If the maximum value in x or X is less than the minimum value in y or Y, print "No War"
# Otherwise, print "War"

