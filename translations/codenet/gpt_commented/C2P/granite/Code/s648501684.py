
# Python code to solve the problem

# Read the values of n, k, and q from user input
n, k, q = map(int, input().split())

# Initialize an array to count occurrences of each element, with size n
arr = [0] * (n + 1)

# Process each query to count occurrences of the queried elements
for _ in range(q):
    temp = int(input())
    arr[temp] += 1

# Check each element from 1 to n to see if its count exceeds the threshold (q - k)
for i in range(1, n + 1):
    # If the count of the element is greater than (q - k), print "Yes"
    if arr[i] > (q - k):
        print("Yes")
    else:
        # Otherwise, print "No"
        print("No")

# End of the Python code
