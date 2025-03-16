# Read an integer input N which represents the number of elements
N = int(input())

# Read a list of integers A from input, which contains N elements
A = list(map(int, input().split()))

# Create a copy of list A and assign it to list B
B = list(A)

# Initialize a counter variable to 1
count = 1

# Iterate through each element in list A
for i in A:
    # Assign the current count value to the position in list B based on the value of i
    B[i - 1] = count
    
    # Increment the count for the next position
    count += 1

# Print the modified list B, unpacking the elements to display them in a single line
print(*B)
