
# Include the standard input/output library

# Function main starts the execution of the program
def main():
# Declare variables i, n, and tmp
i = 0
n = 0
tmp = 0

# Read the number of integers to be entered from the user
n = int(input("Enter the number of integers: "))

# Initialize variables min, max, and sum
min = 1000000
max = -1000000
sum = 0

# Use a for loop to read and process each integer
for i in range(n):
tmp = int(input("Enter the next integer: "))
# Read the next integer from the user and store it in variable tmp
if min > tmp:
min = tmp
# If the current integer is smaller than the current minimum, update the minimum
if max < tmp:
max = tmp
# If the current integer is larger than the current maximum, update the maximum
sum += tmp
# Add the current integer to the sum

# Print the minimum, maximum, and sum of the entered integers
print(min, max, sum)
# Function main ends with a return statement

# Call the main function
main()

