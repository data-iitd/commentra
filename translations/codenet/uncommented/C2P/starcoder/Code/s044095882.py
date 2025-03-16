
n = int(input())
a = [int(input()) for i in range(n)]
count = [0]*n

for i in range(1, n):
    count[a[i]-1] += 1

for i in range(n):
    print(count[i])

#