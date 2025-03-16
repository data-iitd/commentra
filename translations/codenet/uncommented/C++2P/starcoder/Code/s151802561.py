
n = int(input())
A = [int(x) for x in input().split()]
swaps = 0
for i in range(n):
    mini = i
    for j in range(i, n):
        if A[j] < A[mini]:
            mini = j
    if i!= mini:
        swaps += 1
        A[i], A[mini] = A[mini], A[i]
print(*A)
print(swaps)

