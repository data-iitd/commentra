# Take the number of elements in the list 'A' as input
N = int(input())

# Initialize an empty list 'A' with the given size 'N' and fill it with integers using list comprehension
A = [int(x) for x in input().split()]

# Initialize a variable 'ans' with the absolute value of the last element of 'A'
ans = abs(A[-1])

# Add two zeros at the beginning and end of 'A' to make the indexing easier
A = [0] + A + [0]

# Initialize a list 'diff' of size 'N' with zeros
diff = [0 for x in range(N)]

# Iterate through each element 'i' in the list 'A' from the second element to the last one
for i in range(1, N+1):
  # Calculate the difference 'dif' between the current element 'A[i]' and its neighbors
  dif = abs(A[i] - A[i-1]) + abs(A[i] - A[i+1]) - abs(A[i-1] - A[i+1])
  
  # Update the absolute value of the difference between the current and previous elements
  ans += abs(A[i] - A[i-1])
  
  # Store the calculated difference 'dif' in the 'diff' list at the index 'i-1'
  diff[i-1] = dif

# Iterate through each index 'i' in the list 'diff' and print the result
for i in range(N):
  # Print the difference between 'ans' and the corresponding difference in 'diff'
  print(ans - diff[i])
