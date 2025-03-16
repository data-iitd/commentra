
# Take two integers as input from the user
a, b = map(int, input().split())

# Use map() function to apply int() to each element in the list [a, b]
lst = [a+b, a-b, a*b]

# Find the maximum value in the list lst
max_value = max(lst)

# Print the maximum value
print(max_value)