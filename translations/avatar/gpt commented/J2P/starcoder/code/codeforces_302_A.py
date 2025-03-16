
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of elements in the array and the number of queries
n = sc.nextInt()
k = sc.nextInt()

# Initialize an array to hold the input values
arr = [0] * n

# Populate the array with input values
for i in range(n):
    arr[i] = sc.nextInt()

# StringBuffer to store the results of the queries
res = ""

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
        res += "0\n"  # If odd, append "0" to results
    else:
        # If even, check if we can form a valid pair of 1s and 0s
        if (r - l + 1) / 2 <= o and (r - l + 1) / 2 <= e:
            res += "1\n"  # Append "1" if valid pairs can be formed
        else:
            res += "0\n"  # Otherwise, append "0"

# Output the results of all queries
print(res)

# Close the scanner to free resources
sc.close()

# 