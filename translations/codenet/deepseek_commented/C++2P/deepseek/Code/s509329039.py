import sys

def main():
    n, m = map(int, input().split())
    s = [0] * m
    c = [0] * m
    for i in range(m):
        s[i], c[i] = map(int, input().split())
        s[i] -= 1

    for i in range(1000):
        st = str(i)
        if len(st) != n:
            continue
        f = 1
        for j in range(m):
            if st[s[j]] == str(c[j]):
                pass
            else:
                f = 0
                break
        if f:
            print(i)
            return
    print(-1)

if __name__ == "__main__":
    main()
