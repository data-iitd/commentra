SIZE = int(1e5 * 2) + 13  # Define the size of the count array

cnt = [0] * SIZE  # List to count occurrences of each integer

n, k = map(int, input().split())  # Read the number of elements and the threshold k

# Count occurrences of each integer
for _ in range(n):
    x = int(input())
    cnt[x] += 1

# Filter non-zero counts and store them in a list
a = [count for count in cnt if count > 0]

# Sort the list a in ascending order
a.sort()

# Calculate the sum of the smallest k counts in list a
ans = sum(a[:-k])  # Sum all but the last k elements

# Output the result
print(ans)

# <END-OF-CODE>
