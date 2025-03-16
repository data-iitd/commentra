def max(a, b):
    return a if a > b else b

def main():
    data = [0] * 111112  # Adjust size to accommodate 0-indexing
    seq = [0] * 222223   # Adjust size to accommodate 0-indexing

    while True:
        n, k = map(int, input().split())
        if n == 0 and k == 0:
            break

        data = [0] * 111112  # Reset data
        seq = [0] * 222223    # Reset seq

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

        ret = 0
        if data[0]:
            for i in range(p):
                ret = max(ret, seq[i] + seq[i + 2] + 1)
        else:
            for i in range(p):
                ret = max(ret, seq[i])

        print(ret)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
