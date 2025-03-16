
firstline = int(input())  # Read the first line of input, which determines the number of iterations
total = 0  # Initialize a variable to keep track of the total sum
memory = []  # Initialize an empty list to store the decisions

# Loop through the range of firstline
for x in range(firstline):
    A, G = list(map(int, input().split()))  # Read two integers from a single line of input
    if total + A <= 500:  # Check if adding A to total would not exceed 500
        total += A  # Add A to total
        memory.append("A")  # Append "A" to memory
    else:
        total -= G  # Subtract G from total
        memory.append("G")  # Append "G" to memory

# Join the elements of memory into a single string and print it
print("".join(memory))

