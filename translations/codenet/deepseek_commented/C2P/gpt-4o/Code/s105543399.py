n = int(input())  # Read the number of elements
c = 0  # Initialize sum to 0
m = 100000000  # Initialize minimum to a large positive value
M = -100000000  # Initialize maximum to a large negative value

# Loop through each element
for i in range(n):
    a = int(input())  # Read the current number
    if a > M:
        M = a  # Update maximum if current number is greater
    if a < m:
        m = a  # Update minimum if current number is smaller
    c += a  # Add current number to sum

print(m, M, c)  # Print the minimum, maximum, and sum of the numbers

# <END-OF-CODE>
