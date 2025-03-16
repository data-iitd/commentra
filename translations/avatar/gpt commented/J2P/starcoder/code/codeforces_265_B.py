
# <START-OF-CODE>

# Create a Scanner object to read input from the console
scn = Scanner(sys.stdin)

# Read the number of elements in the array
n = scn.nextInt()

# Initialize an array to hold the input integers
arr = [0] * n

# Populate the array with integers from user input
for i in range(n):
    arr[i] = scn.nextInt()

# Initialize the answer with the first element of the array plus one
ans = arr[0] + 1

# Calculate the total distance based on the differences between consecutive elements
for i in range(1, n):
    # Add the absolute difference between the current and previous element, plus 2
    ans += abs(arr[i] - arr[i - 1]) + 2

# Output the final calculated answer
print(ans)

# 