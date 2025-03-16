
# +
import sys

def solve():
    N = int(sys.stdin.readline())
    S = sys.stdin.readline().strip()

    if N == 0:
        return 0

    if N < 4:
        print(0)
        return 0

    nr, nb, ng = 0, 0, 0
    for c in S:
        if c == 'R':
            nr += 1
        elif c == 'B':
            nb += 1
        elif c == 'G':
            ng += 1

    same = 0
    # etot = 0
    for a in range(1, N):
        i = 0
        j = a
        k = 2 * a
        if k >= N:
            break
        while k < N:
            # etot += 1
            # print(f"({etot}) [{a}] ({i}, {j}, {k})", end="")
            if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
                same += 1
                # print(f" ({same})", end="")
            # print()
            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng

    # sum = 0
    # sum2 = 0
    # for k in range(2, N):
    #     for j in range(1, k):
    #         for i in range(0, j):
    #             if j - i == k - j:
    #                 if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
    #                     sum2 += 1
    #                 continue

    #             if S[i] != S[j] and S[i] != S[k] and S[j] != S[k]:
    #                 sum += 1

    # print(tot, same, sum, sum2)
    print(tot - same)

    return 0


if __name__ == "__main__":
    solve()

# 