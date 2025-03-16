
# <START-OF-CODE>

# Create a Scanner object to read input from the console
sc = Scanner(sys.stdin)

# Read the number of elements in the array
n = sc.nextInt()

# Initialize an array to hold the integer values
a = [0] * n

# Populate the array with input values
for i in range(n):
    a[i] = sc.nextInt()

# Read the string input which consists of characters 'A' and 'B'
s = sc.next()

# Initialize a variable to hold the sum of values corresponding to 'B'
sum = 0

# Calculate the initial sum based on the positions of 'B' in the string
for i in range(len(s)):
    ch = s[i]
    if ch == 'B':
        sum += a[i] # Add the value to sum if the character is 'B'

# Store the initial sum as the maximum answer found so far
ans = sum
sum1 = sum

# Iterate through the string to calculate the maximum possible sum
for i in range(len(s)):
    if s[i] == 'A':
        sum1 += a[i] # Increase sum1 if the character is 'A'
    else:
        sum1 -= a[i] # Decrease sum1 if the character is not 'A'

    # Update the maximum answer if the current sum1 is greater
    ans = max(ans, sum1)

# Reset sum1 to the initial sum for the next calculation
sum1 = sum

# Iterate through the string in reverse to calculate the maximum possible sum
for i in range(len(s) - 1, -1, -1):
    if s[i] == 'A':
        sum1 += a[i] # Increase sum1 if the character is 'A'
    else:
        sum1 -= a[i] # Decrease sum1 if the character is not 'A'

    # Update the maximum answer if the current sum1 is greater
    ans = max(ans, sum1)

# Output the maximum sum found
print(ans)

# 