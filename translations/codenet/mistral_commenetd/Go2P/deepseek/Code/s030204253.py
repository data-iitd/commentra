# Read an integer 'n' from the standard input
n = int(input())

# Create a list 'a' of 'n' float elements
a = list(map(float, input().split()))

# Sort the list 'a' using the 'sorted' function
a = sorted(a)

# Initialize an empty list 'na'
na = []

# Iterate through the list 'a' starting from index 2 and append its elements to the list 'na'
for j in range(2, len(a)):
    na.append(a[j])

# Append the average of the first two elements of the original list 'a' to the list 'na'
na.append((a[0] + a[1]) / 2)
a = na

# Print the first element of the sorted list 'a' to the standard output
print(a[0])

# End-of-code comment
