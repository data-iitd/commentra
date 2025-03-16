
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

    nr = S.count('R')
    nb = S.count('B')
    ng = S.count('G')

    same = 0

    for a in range(1, N):
        i = 0
        j = a
        k = 2 * a
        if k >= N:
            break

        while k < N:
            if S[i]!= S[j] and S[i]!= S[k] and S[j]!= S[k]:
                same += 1

            i += 1
            j += 1
            k += 1

    tot = nr * nb * ng

    print(tot - same)

if __name__ == '__main__':
    sys.exit(main())

