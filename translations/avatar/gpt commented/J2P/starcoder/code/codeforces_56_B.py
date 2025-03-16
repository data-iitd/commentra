
# <START-OF-CODE>

# Create a Scanner object to read input from the console
scan = Scanner(sys.stdin)

# Read the length of the array
len = scan.nextInt()

# Initialize an array of the specified length
a = [0] * len

# Populate the array with user input
for i in range(len):
    a[i] = scan.nextInt()

# Initialize variables to track the left and right indices of the mismatch
l = 0
r = 0

# Flags to indicate the state of the search for mismatches
flag = False
isTrue = False

# Loop through the array to find the first and second mismatches
for i in range(len):
    # Check if the current element does not match its expected value
    if a[i]!= i + 1 and not flag:
        # Set the left index to the current position (1-based index)
        l = i + 1
        # Set the flag to indicate the first mismatch has been found
        flag = True
        continue
    # Check for the second mismatch
    if a[i]!= i + 1 and flag:
        # Set the right index to the current position (1-based index)
        r = i + 1
        # Check if the previous element is less than the current element
        if (a[r - 1] - a[r - 2] > 0):
            # Set the isTrue flag to indicate a valid mismatch has been found
            isTrue = True
            break

# Output the result based on whether a valid mismatch was found
print((not isTrue) and (l, r) or (0, 0))

# 