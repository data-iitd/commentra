# Read an integer input which represents the number of elements
n = int(input())

# Read a line of input, split it into individual strings, convert them to integers, and store them in a list
r = [*map(int, input().split())]

# Initialize the answer with the absolute value of the first element in the list
ans = abs(r[0])

# Iterate through the list starting from the second element
for i in range(1, n):
    # Add the absolute difference between the current element and the previous element to the answer
    ans += abs(r[i] - r[i - 1])

# Print the final computed answer
print(ans)
