import sys 

# Read the number of elements
n = int(sys.stdin.readline()) 

# Initialize an array to store the elements
ara = [] 

# Create a map to count the frequency of each element
map = {} 

# Read elements and populate the frequency map
for i in range(n): 
    v = int(sys.stdin.readline()) 
    ara.append(v) 
    # If the element is not in the map, add it with a count of 1
    if v not in map: 
        map[v] = 1
    else: 
        # If it is already in the map, increment its count
        map[v] += 1

# Find the maximum frequency among the elements
max = 0
for i in map.values(): 
    max = max(max, i)

# Create another map to track the order of elements while checking frequency
mm = {}

# Iterate through the original array to find the first element with maximum frequency
for i in range(n): 
    if ara[i] not in mm: 
        mm[ara[i]] = 1
        # Check if the current element's frequency matches the maximum frequency
        if mm[ara[i]] == max: 
            print(ara[i]) 
            break
    else: 
        # Increment the count for the existing element
        mm[ara[i]] += 1
        # Check if the current element's frequency matches the maximum frequency
        if mm[ara[i]] == max: 
            print(ara[i]) 
            break

# END-OF-CODE
