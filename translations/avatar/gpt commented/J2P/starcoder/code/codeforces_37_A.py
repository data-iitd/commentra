
# <START-OF-CODE>

# Create a FastScanner object to read input efficiently
input = FastScanner()

# Read the number of integers to be processed
n = input.nextInt()

# Initialize a HashMap to store the frequency of each integer
map = {}

# Loop through the input integers and populate the frequency map
for i in range(n):
    val = input.nextInt()
    # Update the count of the integer in the map
    map[val] = map.get(val, 0) + 1

# Initialize a variable to track the maximum frequency found
max = -1

# Iterate through the entries in the frequency map to find the maximum frequency
for key, value in map.items():
    # Update max if the current frequency is greater than the current max
    max = max if max > value else value

# Print the maximum frequency and the number of unique integers
print(max, len(map))

# 