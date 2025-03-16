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
        try:
            m, n = map(int, input().split())
            if m == 0:
                break
            book = []
            for _ in range(n):
                tmp = int(input())
                book.append(tmp)

            l = 0
            r = 1500000
            ans = 0
            while l < r:
                mid = (l + r) // 2
                if check(m, mid, book):
                    ans = mid
                    r = mid
                else:
                    l = mid + 1
            
            print(ans)
        except EOFError:
            break

if __name__ == "__main__":
    main()

# <END-OF-CODE>
