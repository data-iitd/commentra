n = int(input())  # Read the number of elements
a = list(map(int, input().split()))  # Read n integers into array a
b = list(map(int, input().split()))  # Read n integers into array b

sum_diff = 0

for i in range(n):
    if a[i] - b[i] > 0:
        sum_diff += a[i] - b[i]

print(sum_diff)
