# Declare variables to store the input values
n, k, q = map(int, input().split())

# Declare an array of size n initialized to 0
arr = [0] * n

# Read q integers and increment the corresponding index in the array arr
for _ in range(q):
    temp = int(input())
    arr[temp - 1] += 1

# Check if the value at each index in arr is greater than q-k
for i in range(n):
    if arr[i] > q - k:
        print("Yes")  # Print "Yes" if the condition is met
    else:
        print("No")  # Print "No" otherwise

# <END-OF-CODE>