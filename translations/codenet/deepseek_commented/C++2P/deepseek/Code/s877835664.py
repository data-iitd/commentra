def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return a // gcd(a, b) * b


def get_prime_factor(n):
    res = {}
    i = 2
    while i * i <= n:
        while n % i == 0:
            res[i] = res.get(i, 0) + 1
            n //= i
        i += 1
    if n != 1:
        res[n] = 1
    return res


def is_prime_number(num):
    if num <= 2:
        return True
    if num % 2 == 0:
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
        a, b = b, a - t * b
        u, v = v, u - t * v
    u %= m
    if u < 0:
        u += m
    return u


def main():
    N, K = map(int, input().split())
    A = [0] + [int(input()) for _ in range(N)]
    cur = 1
    dic = [-1] * (N + 1)
    flg = False
    for i in range(1, K + 1):
        if dic[cur] < 0 or flg:
            dic[cur] = i
            cur = A[cur]
        elif not flg:
            tmp = K - (dic[cur] - 1)
            tmp %= i - dic[cur]
            i = K - tmp
            flg = True
    print(cur)


main()
