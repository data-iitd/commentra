
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of integers to process
n = sc.nextInt()

# Initialize a TreeMap to store integers and their counts
map = TreeMap()

# Process each integer input
while n > 0:
    # Read the next integer
    num = sc.nextInt()

    # Check if there is no lower key in the map
    if map.lower_key(num) is None:
        # If no lower key exists, increment the count for the current number
        val = map.get(num, 0)
        map[num] = val + 1
    else:
        # If there is a lower key, get that key and its count
        key = map.lower_key(num)
        val = map[key]

        # If the count of the lower key is 1, remove it from the map
        if val == 1:
            del map[key]
        else:
            # Otherwise, decrement the count of the lower key
            map[key] = val - 1

        # Increment the count for the current number
        val = map.get(num, 0)
        map[num] = val + 1

    n = n - 1

# Initialize a variable to hold the final answer
ans = 0

# Sum up all the counts in the map
for key in map.keys():
    val = map[key]
    ans += val

# Print the final answer
print(ans)

# 