# Read the number of elements in the list
N = int(input())

# Read the elements of the list and convert them to integers
A = [int(x) for x in input().split()]

# Initialize the answer with the absolute value of the last element in the list
ans = abs(A[-1])

# Modify the list A by adding 0 at the beginning and the end
A = [0] + A + [0]

# Initialize a list to store the differences for each element
diff = [0 for x in range(N)]

# Calculate the initial total distance and the differences for each element
for i in range(1, N + 1):
    # Calculate the difference based on the current element and its neighbors
    dif = abs(A[i] - A[i - 1]) + abs(A[i] - A[i + 1]) - abs(A[i - 1] - A[i + 1])
    
    # Update the total distance by adding the distance to the previous element
    ans += abs(A[i] - A[i - 1])
    
    # Store the calculated difference in the diff list
    diff[i - 1] = dif

# Print the adjusted total distance for each element after removing it
for i in range(N):
    print(ans - diff[i])
