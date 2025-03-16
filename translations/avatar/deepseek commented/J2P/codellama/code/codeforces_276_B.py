
import sys

# Set up input and output streams
inputStreamReader = sys.stdin
bufferedReader = inputStreamReader.buffer
writer = sys.stdout

# Read the input string from the user
str = bufferedReader.readline()

# Create a dictionary to count the frequency of each character in the input string
map = {}

# Initialize a counter for characters with odd frequencies
oddCount = 0

# Iterate through the input string to populate the frequency map
for i in range(len(str)):
    ch = str[i]
    if ch in map:
        map[ch] = map[ch] + 1
    else:
        map[ch] = 1

# Iterate through the map to count characters with odd frequencies
for entry in map.items():
    if entry[1] % 2 != 0:
        oddCount += 1

# Determine the winner based on the count of characters with odd frequencies
if oddCount <= 1 or oddCount % 2 != 0:
    writer.write("First\n")
else:
    writer.write("Second\n")

# Flush the output to ensure the result is printed immediately
writer.flush()

# End of code
