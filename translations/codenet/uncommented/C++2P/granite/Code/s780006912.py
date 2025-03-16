
n = int(input())
array = list(map(int, input().split()))

sum = 0
for i in range(n-1):
  for j in range(i+1, n):
    sum += array[i] * array[j]

print(sum)
