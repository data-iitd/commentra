# Python translation of the given C code

n, k, q = map(int, input().split())  # Read input values n, k, and q from the user

arr = [0] * (n + 1)  # Declare an integer array arr of size n+1 initialized with zeros

for _ in range(q):  # Read q query values from the user and increment the corresponding index in the array arr
    temp = int(input())
    arr[temp] += 1

for i in range(1, n + 1):  # Check each index i in the array arr
    if arr[i] > (q - k):
        print("Yes")
    else:
        print("No")

# Indicate the successful termination of the main function
# <END-OF-CODE>
