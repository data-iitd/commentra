# Declare variables
x = [0] * 10000  # Initialize array x with zeros

# Read the first integer input and store it in the array x at index 0
x[0] = int(input())
# Comment explaining what the line does
# Read the first integer input and store it in the array x

i = 0  # Initialize index

# Read remaining integers and store them in the array x
while x[i] != 0:
    i += 1
    x[i] = int(input())
    # Comment explaining what the loop does
    # This loop reads and stores the remaining integers in the array x

# Print the results
for j in range(i):
    print(f"Case {j + 1}: {x[j]}")
    # Comment explaining what the loop does
    # This loop prints the results for each input integer

# Signal successful termination of the program
# No explicit return needed in Python
