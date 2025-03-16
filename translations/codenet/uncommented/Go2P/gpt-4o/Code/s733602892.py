import sys
import bisect

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints(n):
    return list(map(int, sys.stdin.readline().strip().split()))[:n]

def main():
    N = read_int()
    K = read_int()
    As = read_ints(N)
    Fs = read_ints(N)

    As.sort()
    Fs.sort(reverse=True)
    
    scores = [As[i] * Fs[i] for i in range(N)]
    scores.sort(reverse=True)

    ok = scores[0]
    ng = -1

    while ok - ng > 1:
        mid = (ok + ng) // 2

        is_ok = True
        k = K
        for i in range(N):
            if As[i] * Fs[i] > mid:
                k -= As[i] - mid // Fs[i]
            if k < 0:
                is_ok = False
                break

        if is_ok:
            ok = mid
        else:
            ng = mid

    print(ok)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
