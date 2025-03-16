

n, m = map(int, input().split())
a = [n // m] * m
test = n % m
count = 0
for i in range(test):
    a[count] += 1
    count = (count + 1) % m
print(*a[::-1])
