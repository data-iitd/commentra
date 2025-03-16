
# Prompt the user to enter a number
N = int(input("Enter a number: "))

# Initialize x to 0
x = 0

# Use a for loop to iterate from 1 to N and sum up the numbers
for i in range(1, N+1):
    x += i

# Print the sum of the numbers to the console
print("The sum of numbers from 1 to", N, "is:", x)

# 