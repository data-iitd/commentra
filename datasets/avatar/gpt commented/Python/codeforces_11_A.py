# Read two integers n and d from input
n, d = map(int, input().split())

# Initialize an empty list to store the elements
x = []
# Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
m = 0
q = 0

# Read the elements of the list from input and split them into individual strings
x = input().split()

# Convert the list of strings into a list of integers
for i in range(len(x)):
    x[i] = int(x[i])

# Iterate through the list to compare adjacent elements
for a in range(len(x) - 1):
    # Check if the current element is greater than or equal to the next element
    if x[a] >= x[a + 1]:
        # Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
        q = int((x[a] - x[a + 1]) / d + 1)
        # Update the total adjustments made
        m = m + q
        # Adjust the next element by adding the necessary increments of d
        x[a + 1] = x[a + 1] + q * d

# Print the total number of adjustments made
print(m)
