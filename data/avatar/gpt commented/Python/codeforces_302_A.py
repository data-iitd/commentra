# Read two integers n and m from input
n, m = map(int, input().split())

# Count the number of '-' characters in the input string
sa = input().count("-")

# Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
sa = min([n - sa, sa])

# Initialize an empty list to store results
ss = []

# Loop m times to read pairs of integers a and b
for _ in range(m):
    # Read two integers a and b from input
    a, b = map(int, input().split())
    
    # Calculate the difference b - a
    b -= a
    
    # Check if b is odd and less than or equal to double the count of '-'
    # Append "1\n" to the results if true, otherwise append "0\n"
    ss.append((b % 2 and b <= sa << 1) and "1\n" or "0\n")

# Print the concatenated results from the list
print("".join(ss))
