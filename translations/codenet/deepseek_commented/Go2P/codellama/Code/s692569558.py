
# Create a new scanner to read from standard input
s = input()

# Read the first line of input (which we will ignore)
s = input()

# Read the second line of input
ds = input()

# Split the input string into a slice of strings
dd = ds.split(" ")

# Create a slice of integers to hold the converted values
dn = []

# Convert each string in the slice to an integer
for d in dd:
    dn.append(int(d))

# Initialize the sum variable to hold the result
sum = 0

# Calculate the sum of the products of all pairs of integers in the slice
for i in range(len(dn)):
    for j in range(i+1, len(dn)):
        sum += dn[i] * dn[j]

# Print the result
print(sum)

