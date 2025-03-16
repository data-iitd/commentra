def main():
    n, m, x = map(int, input().split())

    a = []
    p = []
    for i in range(n):
        p.append(int(input()))
        a.append(list(map(int, input().split())))

    ans = 1200001
    for bits in range(1 << n):
        tot = 0
        ok = True
        skill = [0] * m
        for i in range(n):
            if (bits >> i) & 1 == 1:
                tot += p[i]
                for j in range(m):
                    skill[j] += a[i][j]

        for v in skill:
            if v < x:
                ok = False
                break

        if ok:
            if ans > tot:
                ans = tot

    if ans != 1200001:
        print(ans)
    else:
        print("-1")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
