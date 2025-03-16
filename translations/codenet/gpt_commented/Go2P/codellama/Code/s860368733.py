
# Declare variables for the number of elements (n) and the number of comparisons (m)
n, m = map(int, input().split())

# Create a list to hold the heights of n elements
h = list(map(int, input().split()))

# Declare variables for the two elements to compare (a and b)
a, b = map(int, input().split())

# Create a dictionary to keep track of unique elements that are involved in comparisons
counter = {}

# Loop through m comparisons
for i in range(m):
    # Read the indices of the two elements to compare
    a, b = map(int, input().split())
    
    # Compare the heights of the two elements
    if h[a-1] < h[b-1]:
        # If height of a is less than height of b, add a to the counter
        counter[a] = 1
    elif h[a-1] > h[b-1]:
        # If height of a is greater than height of b, add b to the counter
        counter[b] = 1
    elif h[a-1] == h[b-1]:
        # If heights are equal, add both a and b to the counter
        counter[a] = 1
        counter[b] = 1

# Print the number of elements that were not involved in any comparisons
print(n - len(counter))

