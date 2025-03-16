n = int(input())

as = [0] * (n + 1)
bs = [0] * n

for i in range(n):
    as[i] = int(input())

for i in range(n):
    bs[i] = int(input())

sum = 0
for i in range(n):
    a = as[i]
    b = bs[i]
    if a <= b:
        sum += a
        b -= a
        if i+1 <= n:
            an = as[i+1]
            if an <= b:
                sum += an
                as[i+1] = 0
            else:
                sum += b
                as[i+1] -= b
    else:
        sum += b

print(sum)

# 