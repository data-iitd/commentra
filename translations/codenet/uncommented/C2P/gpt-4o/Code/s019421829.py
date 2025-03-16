# AOJ 2275: Fox Number
# 2017.12.11 bal4u@uu

import math

MAX = 707106  # sqrt(10^12/2)
tbl = [0] * (MAX + 1)

sz = 0  # max sz = 57084, prime[0] = 2, prime[57083] = 707099
prime = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
    233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
    353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
    419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
    467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
    547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
    607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
    661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
    739, 743, 751, 757, 761, 769, 773, 787, 797, 809,
    811, 821, 823, 827, 829, 839, 853
]

sqp = [p * p for p in prime[:147]]  # square of prime

def sieve():
    global sz
    for i in range(1, 147):
        k = prime[i]
        for j in range(sqp[i], MAX + 1, k):
            tbl[j] = 1
    for i in range(853, MAX + 1, 2):
        if not tbl[i]:
            prime.append(i)
            sz += 1

def bsch(x):
    l, r = 0, sz
    while l < r:
        m = (l + r) // 2
        if prime[m] == x:
            return m
        if prime[m] < x:
            l = m + 1
        else:
            r = m
    return l - 1

def main():
    global sz
    base = [0] * 1000002
    idx = [1] * 1000002
    pp = [0] * 41  # 2^40 = 1099511627776 >= 10^12

    sieve()

    A, B = map(int, input().split())
    a = A - B
    b = A + B
    if b <= 1:
        print(0)
        return
    if a <= 1:
        a = 2

    sz = bsch(int(math.sqrt(b // 2)))

    for i in range(sz + 1):
        p = prime[i]
        k = 1
        j = p
        while j <= b:
            pp[k] = j
            k += 1
            j *= p
        while k > 1:
            k -= 1
            j = pp[k]
            ll = j * (1 + (a - 1) // j)
            rr = j * (b // j)
            for ll in range(ll, rr + 1, j):
                x = ll - a
                if not idx[x] or base[x] == p:
                    continue
                if idx[x] < k:
                    idx[x] = 0
                else:
                    base[x] = p
                    idx[x] = k

    ans = sum(1 for i in range(int(b - a + 1)) if idx[i])
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
