
import sys

# Create a Scanner object to read input from the console
sc = sys.stdin

# Read the first integer from the input
n = int(sc.readline())

# Check if the input is 1, if so, print the only integer and exit the program
if n == 1:
    print(int(sc.readline())) # Print the only integer
    sys.exit(0) # Exit the program

# Initialize an ArrayList to store the integers
a = []

# Read the rest of the integers and add them to the ArrayList
for i in range(n):
    a.append(int(sc.readline()))

# Sort the ArrayList in ascending order
a.sort()

# Check if the last integer in the ArrayList is 0, if so, print 0 and exit the program
if a[-1] == 0:
    print(0) # Print 0
    sys.exit(0) # Exit the program

# Initialize the answer variable
ans = 0

# Use a while loop to keep applying the function to the ArrayList until it contains only one element
while True:
    if len(a) == 1:
        ans = a[0] # Assign the only remaining integer to the answer variable
        break # Exit the loop
    a = func(a) # Apply the function to the ArrayList and assign the result back to it

# Print the answer
print(ans)

# 