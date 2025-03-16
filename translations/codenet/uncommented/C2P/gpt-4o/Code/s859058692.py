sum = 0
n = int(input())
min = None
max = None

for i in range(n):
    m = int(input())
    sum += m
    if min is None or max is None:
        min = m
        max = m

    if min > m:
        min = m
    if max < m:
        max = m

print(min, max, sum)

# <END-OF-CODE>
