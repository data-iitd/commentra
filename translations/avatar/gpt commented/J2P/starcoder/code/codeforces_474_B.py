
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of elements in the array
n = sc.nextInt()

# Initialize the array to store cumulative sums
arr = [0] * n

# Read the first element and assign it to the first index of the array
arr[0] = sc.nextInt()

# Populate the array with cumulative sums
for i in range(1, n):
    # Read the next integer and add it to the previous cumulative sum
    x = sc.nextInt()
    arr[i] = x + arr[i - 1]

# Read the number of queries
m = sc.nextInt()

# Initialize the array to store the queries
q = [0] * m

# Read each query into the array
for i in range(m):
    q[i] = sc.nextInt()

# Process each query and print the result
for k in range(m):
    print(fun(arr, q[k], n, m) + 1)

# Function to perform binary search on the cumulative sum array
def fun(arr, q, n, m):
    res = 0  # Variable to store the result index
    i = 0
    j = n

    # Perform binary search to find the appropriate index
    while i <= j:
        md = i + (j - i) // 2

        # If the middle element is equal to the query, return the index
        if arr[md] == q:
            return md
        # If the middle element is greater than the query, adjust the search range
        elif arr[md] > q:
            res = md
            j = md - 1
        else:
            i = md + 1

    # Return the last found index where the cumulative sum is less than the query
    return res

# 