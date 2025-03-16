import sys

# Read multiple lines of input from stdin.
# It uses a buffer to accumulate the input and reads line by line until it reaches the end of the file.
def ReadLongLines(times):
	result = []
	buffer = ""
	for i in range(times):
		buffer += sys.stdin.readline()
		result.append(buffer)
		buffer = ""
	return result

# Create a map to store unique elements.
m = {}
lines = ReadLongLines(4)

# Split the second line into individual elements and add them to the map.
a = lines[1].split(" ")
for i in range(len(a)):
	n = int(a[i])
	m[n] = True

# Process the fourth line to toggle the presence of elements in the map.
result = []
b = lines[3].split(" ")
for i in range(len(b)):
	n = int(b[i])
	if n in m:
		del m[n]
	else:
		m[n] = True

# Extract the unique elements from the map and sort them.
result = []
for k, _ in m.items():
	result.append(k)
result.sort()

# Print the sorted list of unique elements.
for j in range(len(result)):
	print(result[j])

# 