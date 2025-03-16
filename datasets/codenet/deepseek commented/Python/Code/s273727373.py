
N = int(input())  # Read the number of elements in the list A
A = list(map(int, input().split()))  # Read the space-separated string of integers and convert it to a list A
B = list(A)  # Create a copy of list A and assign it to B
count = 1  # Initialize a counter variable to 1

# Start a for loop to iterate over each element in list A
for i in A:
  B[i-1] = count  # Assign the value of count to the corresponding index in list B
  count += 1  # Increment the counter variable by 1 after each iteration

# Print the elements of list B separated by spaces
print(*B)

