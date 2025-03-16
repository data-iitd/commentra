
# Read the number of elements N and the maximum distance X
N, X = map(int, input().split())

# Read the lengths of the segments into a list L
L = list(map(int, input().split()))

# Initialize the index i and the distance d
i = 0
d = 0

# Loop through the segments to calculate the total distance
while d <= X and i < N:
    # Add the current segment length to the total distance
    d += L[i]
    
    # Increment the index i
    i += 1

# Output the number of segments used
print(i)

