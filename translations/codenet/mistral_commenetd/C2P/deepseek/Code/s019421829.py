import math

MAX = 707106
tbl = [0] * (MAX + 1)

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

sz = len(prime)

def sieve():
    global sz
    for i in range(1, 147):
        k = prime[i]
        for j in range(prime[i]**2, MAX, k):
            tbl[j] = 1
    for i in range(146, MAX):
        if not tbl[i]:
            prime.append(i)
    sz = len(prime)

base = [0] * 1000002
idx = [1] * 1000002
pp = [0] * 41

def bsch(x):
    l, r = 0, sz
    while l < r:
        m = (l + r) >> 1
        if prime[m] == x:
            return m
        if prime[m] < x:
            l = m + 1
        else:
            r = m
    return l - 1

def main():
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
            j *= p
            k += 1
        for k in range(k - 1, -1, -1):
            j = pp[k]
            ll = j * ((a - 1) // j + 1)
            rr = j * (b // j)
            while ll <= rr:
                x = int(ll - a)
                if idx[x] and base[x] != p:
                    base[x] = p
                    idx[x] = k
                ll += j
    ans = 0
    for i in range(int(b - a + 1)):
        if idx[i]:
            ans += 1
    print(ans)

sieve()
main()
