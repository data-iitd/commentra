# Read an integer input which represents the number of elements
N = int(input())

# Read a list of integers from input and convert them into a list
a = list(map(int, input().split()))

# Sort the list of integers in ascending order
a.sort()

# Create a new list 's' containing every second element from the sorted list 'a', starting from the element at index N
s = [ai for ai in a[N::2]]

# Calculate and print the sum of the elements in the list 's'
print(sum(s))
