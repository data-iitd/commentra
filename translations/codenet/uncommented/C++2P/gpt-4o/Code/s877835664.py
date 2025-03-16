def gcd(a, b):
    return gcd(b, a % b) if b else a

def lcm(a, b):
    return a // gcd(a, b) * b

def get_prime_factors(n):
    res = {}
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            if i in res:
                res[i] += 1
            else:
                res[i] = 1
            n //= i
    if n != 1:
        res[n] = 1
    return res

def is_prime_number(num):
    if num <= 2:
        return True
    elif num % 2 == 0:
        return False

    sqrt_num = int(num**0.5)
    for i in range(3, sqrt_num + 1, 2):
        if num % i == 0:
            return False

    return True

def modinv(a, m):
    b, u, v = m, 1, 0
    while b:
        t = a // b
        a -= t * b
        a, b = b, a
        u -= t * v
        u, v = v, u
    u %= m
    if u < 0:
        u += m
    return u

N, K = map(int, input().split())
A = [0] * (N + 1)

for i in range(1, N + 1):
    A[i] = int(input())

cur = 1
dic = [-1] * (N + 1)
flg = False

for i in range(1, K + 1):
    if dic[cur] < 0 or flg:
        dic[cur] = i
        cur = A[cur]
    elif not flg:
        tmp = K - (dic[cur] - 1)
        tmp %= (i - dic[cur])
        i = K - tmp
        flg = True

print(cur)
# <END-OF-CODE>
