# Declare variables to hold the number of elements (n), the threshold (k), and the number of queries (q)
n, k, q = map(int, input().split())

# Initialize an array to count occurrences of each element, with size n
arr = [0] * n

# Process each query to count occurrences of the queried elements
for _ in range(q):
    temp = int(input())
    arr[temp] += 1  # Increment the count for the queried element

# Check each element from 1 to n to see if its count exceeds the threshold (q - k)
for i in range(n):
    # If the count of the element is greater than (q - k), print "Yes"
    if arr[i] > (q - k):
        print("Yes")
    else:
        # Otherwise, print "No"
        print("No")

# End-of-code
