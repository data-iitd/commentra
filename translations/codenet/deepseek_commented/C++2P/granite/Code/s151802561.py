
n = int(input())
A = list(map(int, input().split()))

sw = 0
for i in range(n):
    mini = i
    for j in range(i, n):
        if A[j] < A[mini]:
            mini = j
    if i!= mini:
        sw += 1
    A[i], A[mini] = A[mini], A[i]

print(*A)
print(sw)

