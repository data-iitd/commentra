# Read the values of n (length of the string) and k (number of queries)
n, k = map(int, input().split())

# Read the input string and store it as a list of characters
a = [i for i in input()]

# Initialize a list to keep track of cumulative counts of "CA" pairs
c = [0] * n

# Loop through the string to count occurrences of "CA" pairs
for i in range(1, n):
    # If the current character is 'C' and the previous character is 'A'
    if a[i] == "C" and a[i - 1] == "A":
        # Increment the count from the previous index
        c[i] = c[i - 1] + 1
    else:
        # Carry forward the previous count if the pair is not "CA"
        c[i] = c[i - 1]

# Process each query to find the number of "CA" pairs in the given range
for w in range(k):
    # Read the range for the current query
    l, r = map(int, input().split())
    # Output the number of "CA" pairs in the range [l, r]
    print(c[r - 1] - c[l - 1])
