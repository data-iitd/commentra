n = int(input())
a = [0] * n
count = [0] * n

for i in range(1, n):
    a[i] = int(input())

for i in range(n):
    count[i] = 0

for i in range(1, n):
    count[a[i] - 1] += 1

for i in range(n):
    print(count[i])

# <END-OF-CODE>
