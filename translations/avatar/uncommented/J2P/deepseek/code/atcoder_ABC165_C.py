def main():
    n, m, q = map(int, input().split())
    a = [0] * q
    b = [0] * q
    c = [0] * q
    d = [0] * q
    for i in range(q):
        a[i], b[i], c[i], d[i] = map(int, input().split())
        a[i] -= 1
        b[i] -= 1

    ans = -100

    def dfs(list_):
        nonlocal ans
        if len(list_) == n:
            score = 0
            for i in range(q):
                if list_[b[i]] - list_[a[i]] == c[i]:
                    score += d[i]
            ans = max(ans, score)
            return
        if list_:
            start = list_[-1]
        else:
            start = 1
        for num in range(start, m + 1):
            list_.append(num)
            dfs(list_)
            list_.pop()
    dfs([])
    print(ans)

if __name__ == "__main__":
    main()
