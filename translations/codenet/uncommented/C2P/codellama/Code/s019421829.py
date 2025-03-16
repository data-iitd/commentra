
# AOJ 2275: Fox Number
# 2017.12.11 bal4u@uu

def sieve():
    global sz, prime, sqp
    tbl = [0] * (MAX+1)
    for i in range(1, 147):
        k = prime[i]
        for j in range(sqp[i], MAX, k): tbl[j] = 1
    for sz in range(146, MAX+1):
        if not tbl[prime[sz]]: prime[sz]
    #print("sz", sz, "prime[", sz-1, "]=", prime[sz-1])
    #sz 57084, prime[57083]=707099

def bsch(x):
    l, r = 0, sz
    while l < r:
        m = (l + r) >> 1
        if prime[m] == x: return m
        if prime[m] < x: l = m + 1
        else: r = m
    return l-1

def main():
    global A, B, a, b, base, idx
    sieve()
    A, B = map(int, input().split())
    a = A-B; b = A+B
    if b <= 1: print("0"); return
    if a <= 1: a = 2

    sz = bsch(int(sqrt((b >> 1))))

    base = [0] * (b-a+1)
    idx = [1] * (b-a+1)
    for i in range(0, sz+1):
        p = prime[i]
        for k in range(1, 41):
            j = p**k
            if j > b: break
            ll = j*(1+(a-1)//j)
            rr = j*(b//j)
            for l in range(ll, rr+1, j):
                x = l-a
                if not idx[x] or base[x] == p: continue
                if idx[x] < k: idx[x] = 0
                else: base[x] = p; idx[x] = k

    ans = 0
    for i in range(b-a, -1, -1):
        if idx[i]: ans += 1
    print(ans)

if __name__ == "__main__":
    main()

