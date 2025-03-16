# Initialize the minimum value to a large number
minA = 1000000001
# Initialize the number of ways to achieve the maximum profit
num = 0

# Read the number of elements and an unused variable 't'
n, t, f = map(int, input().split())
# Create a vector to store the elements
A = list(map(int, input().split()))

# Iterate through the vector to find the maximum profit
for i in range(n):
    # Update the minimum value found so far
    if(minA > A[i]):
        minA = A[i]
    # Check if the current profit is equal to the maximum profit found so far
    elif(f == A[i] - minA):
        num += 1
    # Update the maximum profit and reset the count if a new maximum is found
    else:
        f = A[i] - minA
        num = 1

# Output the number of ways to achieve the maximum profit
print(num)

