
# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read the number of elements in the array
n = sc.nextInt()

# Read the value of k
k = sc.nextLong()

# Initialize an array to hold the input numbers
arr = []

# Read n long integers into the array
for i in range(n):
    arr.append(sc.nextLong())

# Sort the array to facilitate the processing of elements
arr.sort()

# Initialize a counter to keep track of valid elements
count = 0

# Iterate through the sorted array to apply the conditions
for i in range(n):
    # Check if the current element is not divisible by k
    if arr[i] % k!= 0:
        count += 1 # Increment count for valid element
    # Check if the current element is divisible by k and its corresponding k-factor is not in the set
    elif arr[i] / k not in arr:
        count += 1 # Increment count for valid element

# Output the final count of valid elements
print(count)

