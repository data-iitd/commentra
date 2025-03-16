
# Initialize a new scanner for reading input from stdin
sc = input()

# Function to read an integer from standard input
def ri():
    return int(sc.split()[0])

# Function to calculate the average of a slice of float64 numbers
def ave(s):
    sum = 0
    for v in s:
        sum += v
    return sum / len(s)

# Function to calculate the difference between two float64 numbers
def diff(a, b):
    if a > b:
        return a - b
    return b - a

# Main function
n = ri()
a = []
for i in range(n):
    a.append(float(ri()))

# Print the array for debugging purposes (uncomment this line if needed)
# print(a)

# Calculate the average of the array elements
ave = ave(a)

# Initialize variables to store the minimum difference and the index of the element with the minimum difference
minDiff = 999999.9
ansIndex = -1

# Iterate through each element of the array and find the one with the minimum difference from the average
for i, v in enumerate(a):
    diff = diff(v, ave)
    if diff < minDiff:
        minDiff = diff
        ansIndex = i

# Print the index of the element with the minimum difference from the average
print(ansIndex)

# End of the code