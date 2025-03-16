# Take an integer 'n' as input and initialize a list 'a' of size 'n' with integers
n = int(input())
a = list(map(int, input().split()))

# Calculate the middle value 'm1' of the list 'a' by summing up the elements with their alternating signs
m1 = int(sum([a[i] * ((-1)**i) for i in range(n)]) / 2)

# Initialize a new list 'm' of size 'n' with 'None' as default value
m = [None] * n

# Assign the value of 'm1' to the first element of the list 'm'
m[0] = m1

# Calculate the difference between the previous element and the current element for each element in the list 'a' starting from the second one, and assign the result to the corresponding element in the list 'm'
for i in range(1, n):
  m[i] = a[i-1] - m[i-1]

# Print the elements of the list 'm' multiplied by 2
print(' '.join([str(x*2) for x in m]))
