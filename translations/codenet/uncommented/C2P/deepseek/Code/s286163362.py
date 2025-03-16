def max(a, b):
    if a > b:
        return a
    return b

def main():
    while True:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            break

        data = [0] * 111111
        seq = [0] * 222222

        for _ in range(k):
            t = int(input())
            data[t] += 1

        p = 0
        for i in range(1, n + 1):
            if data[i]:
                seq[p] += 1
            else:
                p += 2

        p += 1

        if data[0]:
            for i in range(p):
                ret = max(ret, seq[i] + seq[i + 2] + 1)
        else:
            for i in range(p):
                ret = max(ret, seq[i])

        print(ret)

if __name__ == "__main__":
    main()
