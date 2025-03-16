
# Initialize a list to store the input numbers
l = []

# Read the length of the input list
len = int(input())

# Read the input list from standard input
for i in range(len):
    l.append(int(input()))

# Calculate and print the minimum of the three patterns
print(min(pattern1(l), pattern2(l), pattern3(l)))

