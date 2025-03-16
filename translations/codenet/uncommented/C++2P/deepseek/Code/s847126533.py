import sys

def check(n, wei, book):
    tmp = wei
    n -= 1
    for i in range(len(book)):
        if tmp < book[i]:
            if n > 0:
                n -= 1
                tmp = wei
                if tmp < book[i]:
                    return False
            else:
                return False
        tmp -= book[i]
    return True

for line in sys.stdin:
    m, n = map(int, line.split())
    if m == 0:
        break
    book = list(map(int, sys.stdin.readline().split()))
    
    l = 0
    r = 1500000
    ans = 0
    while l < r:
        mid = (l + r) // 2
        if check(m, mid, book):
            ans = mid
            r = mid
        else:
            l = mid
    
    print(ans)
