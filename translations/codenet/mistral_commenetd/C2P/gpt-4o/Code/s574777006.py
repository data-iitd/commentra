# Declare variables
n = 0
q = 0
x = []
y = []
sum_count = 0

# Read the number of elements in the array x
n = int(input())

# Allocate memory for array x
for i in range(n):
    # Read each element of array x
    x.append(int(input()))

# Read the number of queries
q = int(input())

# Allocate memory for array y
for i in range(q):
    # Read each element of array y
    y.append(int(input()))

# Initialize sum to zero
sum_count = 0

# Check if each element of array y is present in array x and increment sum if found
for i in range(q):
    for j in range(n):
        # Check if current element of y is equal to current element of x
        if y[i] == x[j]:
            # Increment sum if found
            sum_count += 1
            # Break out of inner loop as soon as a match is found
            break

# Print the value of sum
print(sum_count)

# <END-OF-CODE>
