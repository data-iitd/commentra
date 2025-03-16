from collections import defaultdict

# Read input values for N and K
N, K = map(int, input().split())
# Read the list L of length N
L = list(map(int, input().split()))
# Insert a placeholder value at the beginning of the list
L.insert(0, -1)

# Initialize variables for path tracking and loop detection
path = [1]  # Start the path with the first node
ind = 0     # Index to track the position in the path
count = 0   # Not used in the current logic
x = 1       # Current node starting from 1
t = -1      # To store the index of the start of the loop if found
flag = False  # Flag to indicate if a loop is detected
Hash = defaultdict(lambda: 0)  # Dictionary to store the last index of each node

# Iterate through the nodes to detect loops
for i in range(N + 1):
    ne = L[x]  # Get the next node from the list L
    # Check if the next node has been visited before
    if Hash[ne]:
        flag = True  # Set the flag to indicate a loop is found
        t = Hash[ne]  # Store the index where the loop starts
        break  # Exit the loop since a cycle is detected
    # Append the next node to the path
    path.append(ne)
    ind += 1  # Increment the index
    Hash[ne] = ind  # Update the last index of the current node
    x = ne  # Move to the next node

# Check if a loop was detected
if flag == True:
    loop = path[t:]  # Extract the loop from the path
    # Check if K is within the length of the path
    if K < len(path):
        print(path[K])  # Print the K-th node in the path
    else:
        K = K - len(path)  # Adjust K to account for the full path length
        K = K % len(loop)  # Get the position within the loop
        print(loop[K])  # Print the K-th node in the loop
else:
    print(path[K - 1])  # If no loop, print the K-th node in the path
