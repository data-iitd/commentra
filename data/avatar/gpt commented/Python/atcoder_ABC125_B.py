# Read the number of elements
N = int(input())

# Read the values into a list and convert them to integers
V = input().split(" ")
V = [int(i) for i in V]

# Read the costs into a list and convert them to integers
C = input().split(" ")
C = [int(i) for i in C]

# Initialize a list to store the profit differences, starting with 0
profit_differences = [0]

# Initialize a variable to hold the total profit
ans = 0

# Initialize variables to hold current value and cost
X = 0
Y = 0

# Iterate through each item
for i in range(N):
    # Check if the value is greater than the cost
    if V[i] - C[i] > 0:
        # Assign the current value and cost to X and Y
        X = V[i]
        Y = C[i]
        # Calculate the profit and append it to the profit differences list
        profit_differences.append(X - Y)

# Calculate and print the total profit by summing the profit differences
print(sum(profit_differences))
