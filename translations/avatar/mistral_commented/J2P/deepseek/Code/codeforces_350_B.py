import sys

def main():
    n = int(input().strip())
    a = [0] * (n + 1)
    b = [0] * (n + 1)
    num = [0] * (n + 1)

    for i in range(1, n + 1):
        a[i], b[i] = map(int, input().strip().split())

    ss = ""
    ans = 0
    st = [False] * (n + 1)

    for i in range(1, n + 1):
        if a[i] == 1:
            st[i] = True
            sb = []
            x = b[i]
            sss = [i]
            sb.append(str(i)[::-1])
            s = 1

            while not st[x] and num[x] == 1 and x != 0 and a[x] != 1:
                sss = [x]
                sb.append(str(x)[::-1])
                st[x] = True
                x = b[x]
                s += 1

            if s > ans:
                ans = s
                ss = ' '.join(reversed(sb))

    print(ans)
    print(ss)

if __name__ == "__main__":
    main()

