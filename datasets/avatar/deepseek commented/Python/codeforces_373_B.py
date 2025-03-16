
def sum(k):
    # Initialize the return value and other variables
    ret = 0
    pw = 10
    len = 1
    # Loop to calculate the sum of digits from 1 to k
    while True:
        # Calculate the current range of numbers
        cur = min(pw - 1, k)
        prev = pw // 10
        # Add the count of numbers in the current range to the result
        ret += (cur - prev + 1) * len
        # Break the loop if the current range exceeds k
        if pw - 1 >= k:
            break
        # Update the length and power of ten for the next range
        len += 1
        pw *= 10
    return ret

# Read input values for w, m, and k
w, m, k = map(int, input().split())

# Initialize the binary search range
lo = 0
hi = int(1e18)

# Perform binary search to find the maximum md
while hi - lo > 1:
    md = (lo + hi) // 2
    # Calculate the count of numbers in the range [m, m+md-1]
    c = sum(m + md - 1) - sum(m - 1)
    # Adjust the search range based on the condition
    if c * k <= w:
        lo = md
    else:
        hi = md

# Print the result of the binary search
print(lo)

