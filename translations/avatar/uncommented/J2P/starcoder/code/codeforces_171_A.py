
# <START-OF-CODE>

def reverse(n):
    if n < 10:
        return n * 10
    t = n
    r = 0
    while t > 0:
        r = (r * 10) + t % 10
        t = t // 10
    return r

n = int(input())
m = int(input())
t = reverse(m)
print(t + n)

# 