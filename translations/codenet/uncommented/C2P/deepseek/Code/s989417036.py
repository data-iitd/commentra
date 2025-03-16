def main():
    a, b, c = map(int, input().split())
    if b <= c:
        print("NO")
        return
    else:
        d = a
        for i in range(b):
            d = d % b
            if d == c:
                print("YES")
                return
            d += a
    print("NO")

main()
