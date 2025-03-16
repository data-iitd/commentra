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

def main():
    while True:
        m, n = map(int, input().split())
        if m == 0:
            break
        book = list(map(int, input().split()))

        l = 0
        r = 1500000
        while l < r:
            mid = (l + r) // 2
            if check(m, mid, book):
                ans = mid
                r = mid
            else:
                l = mid + 1
        print(ans)

main()

