# Define the number of elements 'n' and the difference 'd' in the input list
n, d = map(int, input().split())

# Initialize an empty list 'x' to store the input elements
x = []

# Initialize variables 'm' and 'q' to 0
m = 0
q = 0

# Read the 'n' elements from the input and convert them to integers
x = input().split()

# Iterate through the list 'x' to find the elements that are not in increasing order
for i in range(len(x)):
    # Check if the current element is greater than or equal to the next element
    if x[i] >= x[i+1]:
        # Calculate the number of elements that need to be added to the next element
        q = int((x[i] - x[i+1]) / d + 1)
        # Add the calculated number of elements to the current and next elements
        m += q
        x[i+1] += q * d

# Print the final result 'm'
print(m)