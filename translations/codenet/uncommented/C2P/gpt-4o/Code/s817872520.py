# AOJ 2601: Evacuation Route
# 2017.11.26 bal4u@uu

INF = 0x5fffffff
a = [0] * 100002
b = [0] * 100002

def getint(p):
    n = 0
    if p[0] == '-':
        p = p[1:]
        while p and p[0].isdigit():
            n = (n << 3) + (n << 1) + (ord(p[0]) & 0xf)
            p = p[1:]
        return -n, p
    while p and p[0].isdigit():
        n = (n << 3) + (n << 1) + (ord(p[0]) & 0xf)
        p = p[1:]
    return n, p

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    p = data[0]
    w, p = getint(p)
    
    ans = 0
    f = 0
    for i in range(1, w + 1):
        k, p = getint(p)
        a[i] = k
        if k == 0:
            f |= 1
        elif k < 0:
            f |= 2
        else:
            ans += k
            
    if ans == 0 or not (f & 1):
        print("0")
        return
    
    if not (f & 2):
        print(ans)
        return

    close = 0
    f = 0
    for i in range(1, w + 1):
        if a[i] == 0:
            close = INF
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (i - f) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = INF
            else:
                k = close - (i - f)
                if k < 0:
                    k = 0
                b[i] = k

    close = 0
    f = w
    for i in range(w, 0, -1):
        if a[i] == 0:
            close = INF
            f = -1
        elif a[i] < 0:
            if f < 0 or close - (f - i) > -a[i]:
                close = -a[i]
                f = i
        else:
            if f < 0:
                b[i] = INF
            else:
                k = close - (f - i)
                if k < 0:
                    k = 0
                if k > b[i]:
                    b[i] = k

    ans = 0
    for i in range(1, w + 1):
        if a[i] > 0:
            if b[i] > a[i]:
                ans += a[i]
            else:
                ans += b[i]
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
