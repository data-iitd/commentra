# Declare variables
n = int(input("Enter the number of integers: "))  # Read the number of inputs
min_val = 1000000  # Initialize min
max_val = -1000000  # Initialize max
sum_val = 0  # Initialize sum

# Loop to read n integers
for _ in range(n):
    tmp = int(input())  # Read the next integer
    
    # Update min if the current number is smaller
    if min_val > tmp:
        min_val = tmp
    
    # Update max if the current number is larger
    if max_val < tmp:
        max_val = tmp
    
    # Add the current number to the sum
    sum_val += tmp

# Print the minimum, maximum, and sum of the numbers
print(min_val, max_val, sum_val)

# <END-OF-CODE>
