
# Read the number of elements
n = int(input())

# Input the elements into the array
l = list(map(int, input().split()))

# Sort the array using a simple bubble sort algorithm
for i in range(n - 1):
    for j in range(i + 1, n):
        # Swap elements if they are in the wrong order
        if l[j] < l[i]:
            l[i], l[j] = l[j], l[i]

# Count the number of valid triplets (i, j, k) such that l[i] + l[j] > l[k]
cnt = 0
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            # Check if the sum of two elements is greater than the third
            if l[i] + l[j] > l[k]:
                cnt += 1  # Increment count if the condition is satisfied
            else:
                break  # Break if the condition is not satisfied (since array is sorted)

# Output the count of valid triplets
print(cnt)

