# Read the first line of input which indicates the number of iterations
firstline = int(input())

# Initialize total to keep track of the accumulated value
total = 0

# Create an empty list to store the memory of actions taken
memory = []

# Loop through the range defined by firstline
for x in range(firstline):
    # Read two integers A and G from input, separated by space
    A, G = list(map(int, input().split()))

    # Check if adding A to total does not exceed the limit of 500
    if total + A <= 500:
        # If within limit, add A to total
        total += A
        # Record the action "A" in memory
        memory.append("A")
    else:
        # If limit exceeded, subtract G from total
        total -= G
        # Record the action "G" in memory
        memory.append("G")

# Print the sequence of actions taken as a single string
print("".join(memory))
