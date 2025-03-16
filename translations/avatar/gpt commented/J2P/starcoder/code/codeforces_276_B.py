
# Initialize input stream to read from standard input
inputStreamReader = input()

# Read a line of input from the user
str = inputStreamReader.readline()

# Create a map to count occurrences of each character
map = {}
oddCount = 0 # Initialize counter for characters with odd occurrences

# Iterate through each character in the input string
for i in range(len(str)):
    ch = str[i]
    # Update the count of the character in the map
    if ch in map:
        map[ch] = map[ch] + 1
    else:
        map[ch] = 1

# Count how many characters have an odd number of occurrences
for key, value in map.items():
    if value % 2!= 0:
        oddCount = oddCount + 1

# Determine the output based on the count of odd occurrences
if oddCount <= 1 or oddCount % 2!= 0:
    print("First") # Output "First" if conditions are met
else:
    print("Second") # Output "Second" otherwise

# 