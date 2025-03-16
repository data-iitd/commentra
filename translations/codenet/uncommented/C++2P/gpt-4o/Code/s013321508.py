import sys
import bisect

def main():
    N, M = map(int, sys.stdin.readline().split())
    
    L = []
    for _ in range(N):
        l = int(sys.stdin.readline().strip())
        L.append(l)

    L.sort()

    for _ in range(M):
        max_L = L[-1]
        if max_L == 0:
            break

        max_L //= 2
        itr = bisect.bisect_left(L, max_L)
        L.insert(itr, max_L)
        L.pop()  # Remove the last element

    ans = sum(L)
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
