
# +build ignore
import sys

def main():
    N = int(input())
    S = input()

    if N == 0:
        print(0)
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
    for a in range(1, N):
        i, j, k = 0, a, 2 * a
        if k >= N:
            break
        for _ in range(k, N, a):
            if S[i]!= S[j] and S[i]!= S[k] and S[j]!= S[k]:
                same += 1
            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng

    print(tot - same)

if __name__ == '__main__':
    sys.exit(main())
