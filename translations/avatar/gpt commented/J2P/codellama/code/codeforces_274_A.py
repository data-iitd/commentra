
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the user
sc = Scanner(System.in)

# Read the number of elements in the array
n = sc.nextInt()

# Read the value of k
k = sc.nextLong()

# Initialize an array to hold the input numbers
arr = [0] * n

# Create a HashSet to store unique elements that meet the criteria
set = set()

# Read n long integers into the array
for i in range(n):
    arr[i] = sc.nextLong()

# Sort the array to facilitate the processing of elements
arr.sort()

# Initialize a counter to keep track of valid elements
count = 0

# Iterate through the sorted array to apply the conditions
for i in range(n):
    # Check if the current element is not divisible by k
    if arr[i] % k != 0:
        count += 1  # Increment count for valid element
        set.add(arr[i])  # Add the element to the set
    # Check if the current element is divisible by k and its corresponding k-factor is not in the set
    elif arr[i] / k not in set:
        count += 1  # Increment count for valid element
        set.add(arr[i])  # Add the element to the set

# Output the final count of valid elements
print(count)

# End of code
