# Take the first line as an input
firstline = int(input())

# Initialize total and memory lists
total = 0
memory = []

# Loop through the given number of lines
for x in range(firstline):
    # Take two integers as input, A and G
    A, G = list(map(int, input().split()))
    
    # Check if adding A to the total memory usage is within the limit
    if total + A <= 500:
        # If yes, add A to the total and append 'A' to the memory list
        total += A
        memory.append("A")
    else:
        # If no, subtract G from the total and append 'G' to the memory list
        total -= G
        memory.append("G")

# Print the final memory state
print("".join(memory))
