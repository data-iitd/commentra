
# Initialize a variable to hold the number of integers to read
n = int(input())

# Initialize a variable to hold the number of integers to read
m = int(input())

# Initialize a list to hold the integers read
a = []

# Initialize a variable to hold the sum of the integers read
sum = 0

# Read m integers from input and calculate their sum
for i in range(m):
    a.append(int(input())) # Read an integer and store it in the list
    sum += a[i] # Add the integer to the sum

# Check if the sum of the integers exceeds n
if sum > n:
    print(-1) # Print -1 if the sum is greater than n
    exit() # Exit the program

# Print the difference between n and the sum of the integers
print(n - sum)

