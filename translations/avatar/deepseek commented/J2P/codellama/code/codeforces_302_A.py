
import sys

# Step 1: Read the input values for n and k
n, k = map(int, input().split())

# Step 2: Read the array elements
arr = list(map(int, input().split()))

# Step 3: Initialize two counters, o and e, to count the number of 1s and 0s in the array, respectively
res = ""
o = 0
e = 0

# Step 4: Iterate through the array to count the number of 1s and 0s
for i in range(n):
    if arr[i] == 1:
        o += 1
    else:
        e += 1

# Step 5: For each query, determine if the length of the subarray is odd
for i in range(k):
    l, r = map(int, input().split())

    if (r - l + 1) % 2 == 1:
        res += "0\n"
    else:
        # Step 6: If the length of the subarray is even, check if the number of 1s and 0s is sufficient
        if (r - l + 1) // 2 <= o and (r - l + 1) // 2 <= e:
            res += "1\n"
        else:
            res += "0\n"

# Step 7: Print the result
print(res, end="")

# END-OF-CODE
