
import sys

# Read the number of elements from the user
n = int(input("Enter the number of elements: "))

# Allocate memory for the array of size 'n' using list()
data = [0]*n

# Read each element of the array from the user
for i in range(n):
    data[i] = int(input(f"Enter element {i+1}: "))

max_val = max(data) # Find the maximum element
index = data.index(max_val) # Find the index of the maximum element

a = sum(data) - max_val # Calculate the sum of all elements except the maximum

# Check if the sum of all elements except the maximum is greater than the maximum
if a > max_val:
    print("Yes")
else:
    print("No")

# Return 0 to indicate successful execution of the program
sys.exit(0)

