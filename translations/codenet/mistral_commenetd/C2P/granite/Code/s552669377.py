

n = int(input("Enter the number of integers: "))
# Read the number of integers to be entered from the user
min = 1000000
max = -1000000
sum = 0
for i in range(n):
# Use a for loop to read and process each integer
tmp = int(input("Enter the next integer: "))
# Read the next integer from the user and store it in variable tmp
if tmp < min:
min = tmp
# If the current integer is smaller than the current minimum, update the minimum
if tmp > max:
max = tmp
# If the current integer is larger than the current maximum, update the maximum
sum += tmp
# Add the current integer to the sum
print(min, max, sum)
# Print the minimum, maximum, and sum of the entered integers

