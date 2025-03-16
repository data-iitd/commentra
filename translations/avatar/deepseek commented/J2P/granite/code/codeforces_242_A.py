

x = int(input()) # Read first integer input
y = int(input()) # Read second integer input
a = int(input()) # Read third integer input
b = int(input()) # Read fourth integer input

count = 0 # Initialize counter to keep track of valid pairs

# Nested loops to iterate through possible pairs (i, j)
for i in range(a, x+1):
    for j in range(b, y+1):
        if i <= j: continue # Skip pairs where i is not greater than j
        count += 1 # Increment counter for each valid pair

print(count) # Print the total count of valid pairs

# Print each valid pair
for i in range(a, x+1):
    for j in range(b, y+1):
        if i <= j: continue # Skip pairs where i is not greater than j
        print(i, j) # Print each valid pair

