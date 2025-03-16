
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
sc = Scanner(System.in)

# Read the number of elements in the array and the number of queries
n = sc.nextInt()
k = sc.nextInt()

# Initialize an array to hold the input values
arr = [None] * n

# Populate the array with input values
for i in range(n):
    arr[i] = sc.nextInt()

# StringBuffer to store the results of the queries
res = StringBuffer()

# Counters for the number of 1s (o) and 0s (e) in the array
o = 0
e = 0

# Count the number of 1s and 0s in the array
for i in range(n):
    if arr[i] == 1:
        o += 1
    else:
        e += 1

# Process each query
for i in range(k):
    # Read the left and right indices for the current query
    l = sc.nextInt()
    r = sc.nextInt()

    # Check if the number of elements in the range is odd
    if (r - l + 1) % 2 == 1:
        res.append("0\n")
    else:
        # If even, check if we can form a valid pair of 1s and 0s
        if (r - l + 1) / 2 <= o and (r - l + 1) / 2 <= e:
            res.append("1\n")
        else:
            res.append("0\n")

# Output the results of all queries
print(res)

# Close the scanner to free resources
sc.close()

# END-OF-CODE
