
import sys

def main():
    N, K = map(int, sys.stdin.readline().split())
    As = list(map(int, sys.stdin.readline().split()))
    Fs = list(map(int, sys.stdin.readline().split()))

    As.sort()
    Fs.sort(reverse=True)
    scores = [As[i] * Fs[i] for i in range(N)]
    scores.sort(reverse=True)

    ok = scores[0]
    ng = -1
    while ok - ng > 1:
        mid = (ok + ng) // 2

        isOK = True
        k = K
        for i in range(N):
            if As[i] * Fs[i] > mid:
                k -= As[i] - mid // Fs[i]
            if k < 0:
                isOK = False
                break

        if isOK:
            ok = mid
        else:
            ng = mid

    print(ok)

if __name__ == '__main__':
    main()

