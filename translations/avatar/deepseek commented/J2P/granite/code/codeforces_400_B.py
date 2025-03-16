

n, m = map(int, input().split()) # Read the first two integers input (number of strings and possibly not used)
arrs = [] # Initialize list to store strings
for i in range(n):
    arrs.append(input()) # Read each string and store it in the list

length = [] # Initialize list to store differences
returnDex = 0 # Initialize returnDex to store the result

for tmp in arrs: # Loop through each string in the list
    dexG = tmp.find("G") # Find the index of 'G' in the string
    dexS = tmp.find("S") # Find the index of 'S' in the string
    if dexG > dexS: # Check if 'G' comes after 'S'
        returnDex = -1 # Set returnDex to -1 if 'G' is after 'S'
    length.append(dexS - dexG) # Calculate and store the difference in length list

set = set() # Initialize set to store unique differences
for len in length: # Loop through each difference in the length list
    set.add(len) # Add the difference to the set

if returnDex == -1: # Check if returnDex is -1
    print(returnDex) # Print -1 if 'G' comes after 'S'
else:
    print(len(set)) # Print the length of the set if 'G' does not come after 'S'

