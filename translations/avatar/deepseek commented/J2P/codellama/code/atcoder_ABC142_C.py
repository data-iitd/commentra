
# Step 1: Read the input value N, which represents the number of elements.
N = int(input())

# Step 2: Create a map idorder to store the elements and their corresponding positions.
idorder = {}

# Step 3: Read each element and store its value and position in the map.
for i in range(1, N+1):
    A = int(input())
    idorder[A] = i

# Step 4: Print the positions of the elements in the order they were read.
for i in range(1, N+1):
    print(idorder[i], end=" ")

# 