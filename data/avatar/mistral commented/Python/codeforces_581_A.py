# Get user input as a list of strings, split by space character, and convert each to an integer
a, b = map(int, input().split())

# Find the minimum value between 'a' and 'b'
min_value = min(a, b)

# Find the maximum value between 'a' and 'b'
max_value = max(a, b)

# Print the minimum value and the average of the difference between minimum and maximum values
print(min_value, int((max_value - min_value) / 2))