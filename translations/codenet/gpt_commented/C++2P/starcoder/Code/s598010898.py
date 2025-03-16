# Define a long long type for large integers
a = int(input())
b = list(map(int, input().split()))
c = list(map(int, input().split()))

sum = 0
for i in range(a):
    if b[i] - c[i] > 0:
        sum += b[i] - c[i]

print(sum)

