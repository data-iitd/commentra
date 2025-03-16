
# <START-OF-CODE>

# Read an integer n from input
n = int(input())

# Calculate the square of n
square = n * n

# Initialize lists to hold odd and even numbers
odd = []
even = []

# Populate the odd and even lists with numbers from 1 to square
for i in range(1, square + 1):
    if i % 2 == 0:
        even.append(i)
    else:
        odd.append(i)

# Calculate the number of loops and the division for pairing
loop = square / n
div = loop / 2

# Debug output to check the value of div
print(div)

# Loop through the number of rows to print the pairs
for i in range(1, loop + 1):
    # For each row, print div pairs of numbers
    for j in range(div):
        # Alternate between odd and even pairs based on the row number
        if i % 2 == 1:
            # For odd rows, print an odd number and the last even number
            print(odd.pop(0), even.pop())
        else:
            # For even rows, print an even number and the last odd number
            print(even.pop(0), odd.pop())
    # Move to the next line after printing pairs for the current row
    print()

# 