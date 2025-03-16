

n = int(input())
as = list(map(int, input().split()))
bs = list(map(int, input().split()))

sum = 0
for i in range(n):
    a = as[i]
    b = bs[i]
    if a <= b:
        sum += a
        b -= a
    if i+1 < n:
        an = as[i+1]
        if an <= b:
            sum += an
            as[i+1] = 0
        else:
            sum += b
            as[i+1] -= b

print(sum)
