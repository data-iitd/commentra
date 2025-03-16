
from collections import defaultdict

# Read the values of N and K from input
N, K = map(int, input().split())

# Read the list L of integers from input
L = list(map(int, input().split()))

# Insert -1 at the beginning of the list L
L.insert(0, -1)

# Initialize the path list with the first element 1
path = [1]

# Initialize index tracker to 0
ind = 0

# Initialize count to 0
count = 0

# Initialize current position to 1
x = 1

# Initialize loop start index to -1
t = -1

# Initialize flag to indicate loop detection
flag = False

# Initialize a defaultdict to keep track of indices of elements in path
Hash = defaultdict(lambda: 0)

# Main loop to traverse the path
for i in range(N + 1):
    # Get the next element in the path
    ne = L[x]
    
    # Check if the next element is already in the Hash
    if Hash[ne]:
        # Loop detected, set flag and record the start index
        flag = True
        t = Hash[ne]
        break
    
    # Append the next element to the path and update index
    path.append(ne)
    ind += 1
    
    # Update the Hash with the current index
    Hash[ne] = ind
    
    # Move to the next element
    x = ne

# Check if a loop is detected
if flag:
    # Create a loop slice from the detected start index to the end
    loop = path[t:]
    
    # If K is within the bounds of the path length, print the K-th element
    if K < len(path):
        print(path[K])
    else:
        # Adjust K for the loop length
        K = K - len(path)
        K = K % len(loop)
        # Print the K-th element of the loop
        print(loop[K])
else:
    # If no loop, print the (K-1)-th element of the path
    print(path[K - 1])