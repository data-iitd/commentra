
# <START-OF-CODE>

# Create a BufferedReader to read input from the standard input stream
infile = open(0)

# Read the first line of input and convert it to a character array
arr = infile.readline().strip()

# Get the length of the character array
N = len(arr)

# Initialize a HashSet to store unique strings (not used in this code)
set = set()

# Read the number of queries K
K = int(infile.readline())

# Initialize the result counter
res = 0

# Loop through each query
for k in range(K):
    # Read the input string for the current query
    input = infile.readline().strip()

    # Initialize counters for characters in the input string
    a = 0
    b = 0

    # Iterate through the character array
    for i in range(N):
        # Count occurrences of the first character of the input string
        if arr[i] == input[0]:
            a += 1
        # Count occurrences of the second character of the input string
        elif arr[i] == input[1]:
            b += 1
        # If neither character is found, update the result and reset counters
        else:
            res += min(a, b)
            a = b = 0

    # Add the minimum count of the two characters to the result
    res += min(a, b)

# Output the final result
print(res)

# 