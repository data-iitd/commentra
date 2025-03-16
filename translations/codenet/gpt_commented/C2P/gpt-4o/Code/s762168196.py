# Declare a list to hold up to 10,000 integers
a = []
# Initialize variables to hold the minimum, maximum, and sum of the integers
min_val = float('inf')
max_val = float('-inf')
sum_val = 0

# Read the number of integers to be processed
n = int(input())

# Read n integers from input and calculate their sum
for i in range(n):
    num = int(input())  # Read each integer
    a.append(num)      # Add the integer to the list
    sum_val += num     # Add the integer to the sum

# Iterate through the list to find the minimum and maximum values
for num in a:
    if num > max_val:
        max_val = num  # Update max if the current element is greater
    if num < min_val:
        min_val = num  # Update min if the current element is smaller

# Print the minimum, maximum, and sum of the integers
print(min_val, max_val, sum_val)

# <END-OF-CODE>
