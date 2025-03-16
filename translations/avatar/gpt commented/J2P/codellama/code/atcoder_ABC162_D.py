
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the console
sc = Scanner(System.in)

# Read the integer n which represents the length of the string
n = sc.nextInt()

# Read the string s which contains characters 'R', 'G', and 'B'
s = sc.next()

# Initialize counters for each color
rc = 0  # Counter for 'R'
gc = 0  # Counter for 'G'
bc = 0  # Counter for 'B'

# Count the occurrences of each character in the string
for i in range(len(s)):
    if s[i] == 'R':
        rc += 1  # Increment red counter
    elif s[i] == 'G':
        gc += 1  # Increment green counter
    else:
        bc += 1  # Increment blue counter

# Calculate the initial result based on the product of the counts
result = rc * gc * bc

# Iterate through all pairs of indices (i, k) to check conditions
for i in range(1, n + 1):
    for k in range(i + 1, n + 1):
        # Check if the sum of indices is even
        if (i + k) % 2 == 0:
            # Get the characters at the current indices
            is = s[i - 1]
            ks = s[k - 1]
            js = s[(i + k) // 2 - 1]

            # Check if all three characters are different
            if is != ks and ks != js and js != is:
                result -= 1  # Decrease the result if the condition is met

# Output the final result
print(result)

# END-OF-CODE
