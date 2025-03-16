import sys

def find_triplet(n, arr):
    f = 0
    for k in range(n):
        t = arr[k]
        for i in range(n):
            for j in range(n - 1):
                if i != j and t == arr[i] + arr[j]:
                    f = 1
                    return f"{k + 1} {i + 1} {j + 1}"
    return "-1"

# Read input
n = int(input().strip())
arr = list(map(int, input().strip().split()))

# Find and print the result
result = find_triplet(n, arr)
print(result)
