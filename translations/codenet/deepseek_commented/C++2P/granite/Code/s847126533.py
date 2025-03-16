
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

while True:
    m, n = map(int, input().split())
    if m == 0:
        break
    book = [int(input()) for _ in range(n)]

    # Binary search to find the maximum weight a person can carry
    l = 0
    r = 1500000
    ans = 0
    while l < r:
        mid = (l + r) // 2
        if check(m, mid, book):
            ans = mid
            r = mid  # Adjust the right boundary
        else:
            l = mid  # Adjust the left boundary
    print(ans)

