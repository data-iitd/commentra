
n = int(input())
A = list(map(int, input().split()))

for i in range(n):
  mini = i
  for j in range(i, n):
    if A[j] < A[mini]:
      mini = j
  A[i], A[mini] = A[mini], A[i]

print(*A)
print(sum(i!= mini for i, mini in enumerate(A)))

