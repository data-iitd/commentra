
# <START-OF-CODE>

# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read the number of elements in the array
n = sc.nextInt()

# Initialize an array to hold the integers and a variable to store the sum
arr = [0] * n
sum = 0

# Read the integers into the array and calculate the sum
for i in range(n):
    arr[i] = sc.nextInt()
    sum += arr[i] # Accumulate the sum of the elements

# Initialize a counter for valid indices and a StringBuilder for output
c = 0
sb = StringBuilder()

# Check each element to see if it can be the "removed" element
for i in range(n):
    # Check if removing arr[i] results in the average of the remaining elements being equal to arr[i]
    if ((sum - arr[i]) % (n - 1) == 0 and (sum - arr[i]) / (n - 1) == arr[i]):
        c += 1 # Increment the count of valid indices
        sb.append(str(i + 1) + " ") # Append the 1-based index to the StringBuilder

# Output the count of valid indices
print(c)

# Output the indices of valid elements
print(sb.toString())

# 