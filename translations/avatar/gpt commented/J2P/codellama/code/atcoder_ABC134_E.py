
# Create a TreeMap to store integers and their counts
map = TreeMap()

# Process each integer input
while n > 0:
    # Read the next integer
    num = int(input())
    
    # Check if there is no lower key in the map
    if map.lower_key(num) == None:
        # If no lower key exists, increment the count for the current number
        val = map.get(num, 0)
        map.put(num, val + 1)
    else:
        # If there is a lower key, get that key and its count
        key = map.lower_key(num)
        val = map.get(key)
        
        # If the count of the lower key is 1, remove it from the map
        if val == 1:
            map.remove(key)
        else:
            # Otherwise, decrement the count of the lower key
            map.put(key, val - 1)
            
        # Increment the count for the current number
        val = map.get(num, 0)
        map.put(num, val + 1)
    
    # Decrement the number of integers to process
    n -= 1

# Initialize a variable to hold the final answer
ans = 0

# Sum up all the counts in the map
for key in map.keys():
    val = map.get(key)
    ans += val

# Print the final answer
print(ans)

