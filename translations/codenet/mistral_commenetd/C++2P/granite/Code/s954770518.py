
# Read 10 integers from the user and store them in the list's'
s = []
for i in range(10):
    s.append(int(input()))

# Sort the list's' in ascending order using the built-in sort function
s.sort()

# Print the 4th, 5th and 6th smallest elements from the sorted list's'
for i in range(9, 6, -1):
    print(s[i])
