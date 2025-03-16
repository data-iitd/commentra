
# Import the Scanner class from the java.util package
from java.util import Scanner

# Define the maximum size for the dp array
maxn = 4010

# Create a Scanner object to read input from the console
scanner = Scanner(System.in)

# Read the total number of items (n) to be processed
n = scanner.nextInt()

# Read three integer values (a, b, c) which represent the sizes of items
a = scanner.nextInt()
b = scanner.nextInt()
c = scanner.nextInt()

# Store the sizes of items in an array for easier access
arr = [a, b, c]

# Initialize a dp array to store the maximum number of items that can be formed
dp = [Integer.MIN_VALUE] * maxn

# Base case: zero items can be formed with zero size
dp[0] = 0

# Iterate through each item size (a, b, c)
for i in range(3):
    # Update the dp array for each possible size from the current item size
    for j in range(arr[i], dp.length):
        # Calculate the maximum number of items that can be formed
        dp[j] = max(dp[j], dp[j - arr[i]] + 1)

# Output the maximum number of items that can be formed with size n
print(dp[n])

# END-OF-CODE
