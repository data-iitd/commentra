
# <START-OF-CODE>

# Create a Scanner object to read input from the user
sc = Scanner(sys.stdin)

# Read the number of elements
n = int(sc.next())

# Initialize an array to store the input values
v = [0] * 100010

# Read n integers from input and store them in the array v
for i in range(n):
    v[i] = int(sc.next())

# Initialize arrays to count occurrences of values at different positions
vo = [0] * 100010 # Odd indexed counts
ve = [0] * 100010 # Even indexed counts
vt = [0] * 100010 # Total counts

# Fill the count arrays with zeros
for i in range(100010):
    vo[i] = 0
    ve[i] = 0
    vt[i] = 0

# Count occurrences of each number in odd and even indexed positions
for i in range(n):
    vt[v[i]] += 1 # Increment total count for the value
    if i % 2 == 0:
        ve[v[i]] += 1 # Increment even indexed count
    else:
        vo[v[i]] += 1 # Increment odd indexed count

# Sort the count arrays in descending order
vo.sort(reverse=True)
ve.sort(reverse=True)
vt.sort(reverse=True)

# Initialize the answer variable
ans = 0

# Determine the answer based on the counts of the most frequent elements
if vo[0] + ve[0] == vt[0]:
    # If the most frequent odd and even counts sum to the total count
    ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0])
else:
    # Otherwise, calculate the answer based on the most frequent counts
    ans = n - vo[0] - ve[0]

# Output the final answer
print(ans)

# Close the scanner to prevent resource leaks
sc.close()

# 